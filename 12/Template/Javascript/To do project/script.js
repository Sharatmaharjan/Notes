// Initialize an empty array to hold the tasks


// Function to load tasks from local storage on page load
window.onload = function() {
    // Check if tasks are stored in localStorage
    
        // If tasks are found, retrieve them and parse from JSON format into a JavaScript array
        
        
        // Call the renderTasks function to display the tasks on the page
        renderTasks();
    }
};


// Function to add a new task
function addTask() {
    // Get the input element where the user types the task
    
    
    // Get the trimmed value from the input field (removes extra spaces before and after the task)
    

    // Check if the task text is empty (if the user hasn't entered anything)
    
        // If input is empty, show an alert to the user
        
        // Stop the function and do not proceed further
    
    }

    // If the input is not empty, add the new task to the tasks array
    

    // Clear the input field after the task is added
    

    // Call the saveTasks function to update the local storage with the new tasks list
    saveTasks();

    // Call the renderTasks function to update the visible task list on the page
    renderTasks();
}


// Function to render the tasks on the page
function renderTasks() {
    // Get the task list container element by its ID
    
    
    // Clear the task list before rendering new tasks
    

    // Loop through each task in the tasks array
    tasks.forEach((task, index) => {
        // Create a new <li> element for each task
        
        
        // Set the text content of the <li> to the task name
        

        // Create a new button element for deleting the task
        
        
        // Set the text of the delete button to "Delete"
        
        
        // Assign a function to delete the task when the delete button is clicked
        deleteButton.onclick = function() {
            deleteTask(index);  // Pass the task index to deleteTask function
        };

        // Append the delete button to the <li> element
        
        
        // Append the <li> (task) element to the task list container
        
    });
}

// Function to delete a task
function deleteTask(index) {
    // Remove the task at the specified index from the tasks array
    

    // Call the saveTasks function to update the local storage with the updated tasks array
    saveTasks();

    // Call the renderTasks function to re-render the task list on the page after deletion
    renderTasks();
}


// Function to save tasks to local storage
function saveTasks() {
    // Convert the tasks array into a JSON string and save it in localStorage under the key "tasks"
    
}



// Add event listener to check for Enter key
document.getElementById("task-input").addEventListener("keydown", function(event) {
    if (event.key === "Enter") {
        addTask();
    }
});
