<template>
  <div class="container">
    <Header @toggle-add-task="toggleAddTask" text="Task Tracker" :showAddTask = "showAddTask" />
    <div v-show="showAddTask">
      <AddTask @add-task="addTask"/>
    </div>
    <Tasks @toggle-reminder="toggleReminder" @delete-task="deleteTask" :tasks="tasks"/>
  </div>
</template>

<script>
import Header from './components/Header'
import Tasks from './components/Tasks'
import AddTask from './components/AddTask'

export default {
  name: 'App',
  components:{
    Header,
    Tasks,
    AddTask,
  },
  data(){
    return{
      tasks: [],
      showAddTask : false
    }
  },
  async created(){
    this.tasks = await this.fetchTasks()
  },
  methods:{
    async fetchTasks(){
      const res = await fetch('api/tasks')
      const data = res.json();
      return data
    },
    async fetchTask(id){
      const res = await fetch(`api/tasks/${id}`)
      return res
    },
    toggleAddTask(){
      this.showAddTask = !this.showAddTask
    },
    async addTask(newTask){
      const res = await fetch('api/tasks', {
        method: 'POST',
        headers: {
          'Content-type' : 'application/json',
        },
        body : JSON.stringify(newTask)
      })
      const data = await res.json()
      this.tasks = [...this.tasks, data]
    },  
    async deleteTask(id){
      if(confirm('Are you sure?')){
        const res = await fetch(`api/tasks/${id}`,{
          method : 'DELETE',
        })
        
        res.status == 200 ? (this.tasks = this.tasks.filter((task)=>task.id!=id)):
        alert('Error Deleting Task')
      }
    },
    async toggleReminder(id){
      const taskToToggle = await this.fetchTask(id)
      const upTask = {...taskToToggle,}
      this.tasks = this.tasks.map((task)=>task.id==id
      ?{...task,reminder:!task.reminder}:task)
    },
  }
}
</script>

<style>
  @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400&display=swap');

  body {
    font-family: 'Poppins', sans-serif;
  }

  .container{
    max-width: 400px;
    margin:30px auto;
    overflow: auto;
    min-height: 300px;
    border: 1px solid steelblue;
    padding: 30px;
    border-radius: 10px;
  }

  .btn{
    display: inline-block;
    border-radius: 5px;
    background: black;
    font-family: inherit;
    color:ivory;
    padding : 10px 20px;
    margin: 5px;
    cursor: pointer;
    text-decoration: none;
    font-size: 20px;
  }
</style>
 