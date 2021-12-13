<template>
  <div class="container">
    <Header @toggle-add-task="toggleAddTask" text="Task Tracker" :showAddTask = "showAddTask" />
    <Footer />
  </div>
</template>

<script>
import Header from './components/Header'  
import Footer from './components/Footer.vue'

export default {
  name: 'App',
  components:{
    Header,
    Footer,
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
    toggleAddTask(){
      this.showAddTask = !this.showAddTask
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
 