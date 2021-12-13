<template>
    <header>
        <h1>{{text}}</h1>
        <Button @btn-click="$emit('toggle-add-task')" 
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