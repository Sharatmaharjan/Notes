// script.js

// Initialize an empty array to hold the tasks
let tasks = [];

// Function to load tasks from local storage on page load
window.onload = function() {
    if (localStorage.getItem("tasks")) {
        tasks = JSON.parse(localStorage.getItem("tasks"));
        renderTasks();
    }
};

// Function to add a new task
function addTask() {
    const taskInput = document.getElementById("task-input");
    const taskText = taskInput.value.trim();

    // Check if input is empty
    if (taskText === "") {
        alert("Please enter a task.");
        return;
    }

    // Add task to tasks array
    tasks.push(taskText);
    taskInput.value = ""; // Clear input field

    // Update local storage and render the updated task list
    saveTasks();
    renderTasks();
}

// Function to render the tasks on the page
function renderTasks() {
    const taskList = document.getElementById("task-list");
    taskList.innerHTML = ""; // Clear the list before rendering

    tasks.forEach((task, index) => {
        const li = document.createElement("li");
        li.textContent = task;

        // Create a delete button for each task
        const deleteButton = document.createElement("button");
        deleteButton.textContent = "Delete";
        deleteButton.onclick = function() {
            deleteTask(index);
        };

        li.appendChild(deleteButton); // Add button to the list item
        taskList.appendChild(li); // Add the list item to the task list
    });
}

// Function to delete a task
function deleteTask(index) {
    tasks.splice(index, 1); // Remove the task from the array
    saveTasks();
    renderTasks(); // Re-render the updated list
}

// Function to save tasks to local storage
function saveTasks() {
    localStorage.setItem("tasks", JSON.stringify(tasks));
}
