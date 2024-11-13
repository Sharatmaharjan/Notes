// script.js

// Initialize an empty array to hold the tasks
let tasks = [];

// Function to load tasks from local storage on page load
window.onload = function() {
    // Check if tasks are stored in localStorage
    if (localStorage.getItem("tasks")) {
        // If tasks are found, retrieve them and parse from JSON format into a JavaScript array
        tasks = JSON.parse(localStorage.getItem("tasks"));
        
        // Call the renderTasks function to display the tasks on the page
        renderTasks();
    }
};


// Function to add a new task
function addTask() {
    // Get the input element where the user types the task
    const taskInput = document.getElementById("task-input");
    
    // Get the trimmed value from the input field (removes extra spaces before and after the task)
    const taskText = taskInput.value.trim();

    // Check if the task text is empty (if the user hasn't entered anything)
    if (taskText === "") {
        // If input is empty, show an alert to the user
        alert("Please enter a task.");
        return;  // Stop the function and do not proceed further
    }

    // If the input is not empty, add the new task to the tasks array
    tasks.push(taskText);

    // Clear the input field after the task is added
    taskInput.value = ""; 

    // Call the saveTasks function to update the local storage with the new tasks list
    saveTasks();

    // Call the renderTasks function to update the visible task list on the page
    renderTasks();
}


// Function to render the tasks on the page
function renderTasks() {
    // Get the task list container element by its ID
    const taskList = document.getElementById("task-list");
    
    // Clear the task list before rendering new tasks
    taskList.innerHTML = ""; 

    // Loop through each task in the tasks array
    tasks.forEach((task, index) => {
        // Create a new <li> element for each task
        const li = document.createElement("li");
        
        // Set the text content of the <li> to the task name
        li.textContent = task;

        // Create a new button element for deleting the task
        const deleteButton = document.createElement("button");
        
        // Set the text of the delete button to "Delete"
        deleteButton.textContent = "Delete";
        
        // Assign a function to delete the task when the delete button is clicked
        deleteButton.onclick = function() {
            deleteTask(index);  // Pass the task index to deleteTask function
        };

        // Append the delete button to the <li> element
        li.appendChild(deleteButton); 
        
        // Append the <li> (task) element to the task list container
        taskList.appendChild(li); 
    });
}

// Function to delete a task
function deleteTask(index) {
    // Remove the task at the specified index from the tasks array
    tasks.splice(index, 1);

    // Call the saveTasks function to update the local storage with the updated tasks array
    saveTasks();

    // Call the renderTasks function to re-render the task list on the page after deletion
    renderTasks();
}


// Function to save tasks to local storage
function saveTasks() {
    // Convert the tasks array into a JSON string and save it in localStorage under the key "tasks"
    localStorage.setItem("tasks", JSON.stringify(tasks));
}



// Add event listener to check for Enter key
document.getElementById("task-input").addEventListener("keydown", function(event) {
    if (event.key === "Enter") {
        addTask();
    }
});
