<template>
    <header>
        <h1>{{text}}</h1>
        <Button v-show:"homePage"
        @btn-click="$emit('toggle-add-task')" 
        :color="showAddTask?'red':'green'" 
        :text="showAddTask?'Close' : 'Add Task'"></Button>
    </header>
</template>

<script>
import Button from './Button'

export default {
    name : 'Header',
    props:{
        text:String,
        showAddTask : Boolean
    },
    components:{
        Button
    },
    computed:{
        homePage(){
            if(this.$route.path==='/'){
                return true
            }else{
                return false
            }
        }
    }
    // emits:['toggle-add-task']
}
</script>

<style scoped>
    header{
        display : flex;
        align-content: center;
        justify-content: space-between;
        margin-bottom: 20px;
    }
</style>