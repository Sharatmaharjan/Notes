// Function to calculate the area of the rectangle
function calculateAreaOfRectangle() {
    const length = parseFloat(document.getElementById('length').value);
    const width = parseFloat(document.getElementById('width').value);

    if (!isNaN(length) && !isNaN(width) && length > 0 && width > 0) {
        const area = length * width;
        document.getElementById('rectangle-result').textContent = `Area: ${area} square units`;
    } else {
        document.getElementById('rectangle-result').textContent = 'Please enter valid positive numbers for both length and width.';
    }
}

// Function to calculate Simple Interest
function calculateSimpleInterest() {
    const principal = parseFloat(document.getElementById('principal').value);
    const rate = parseFloat(document.getElementById('rate').value);
    const time = parseFloat(document.getElementById('time').value);

    if (!isNaN(principal) && !isNaN(rate) && !isNaN(time) && principal > 0 && rate > 0 && time > 0) {
        const interest = (principal * rate * time) / 100;
        document.getElementById('interest-result').textContent = `Simple Interest: ${interest} units`;
    } else {
        document.getElementById('interest-result').textContent = 'Please enter valid positive numbers for principal, rate, and time.';
    }
}

// Function to calculate the area of the circle
function calculateAreaOfCircle() {
    const radius = parseFloat(document.getElementById('radius').value);

    if (!isNaN(radius) && radius > 0) {
        const area = Math.PI * Math.pow(radius, 2);
        document.getElementById('circle-result').textContent = `Area: ${area.toFixed(2)} square units`;
    } else {
        document.getElementById('circle-result').textContent = 'Please enter a valid positive radius.';
    }
}

// Function to calculate BMI
function calculateBMI() {
    const weight = parseFloat(document.getElementById('weight').value);
    const height = parseFloat(document.getElementById('height').value);

    if (!isNaN(weight) && !isNaN(height) && weight > 0 && height > 0) {
        const bmi = weight / Math.pow(height, 2);
        document.getElementById('bmi-result').textContent = `BMI: ${bmi.toFixed(2)}`;
    } else {
        document.getElementById('bmi-result').textContent = 'Please enter valid positive weight and height.';
    }
}

// Function to convert Celsius to Fahrenheit
function convertToFahrenheit() {
    const celsius = parseFloat(document.getElementById('celsius').value);
    if (!isNaN(celsius)) {
        const fahrenheit = (celsius * 9 / 5) + 32;
        document.getElementById('temperature-result').textContent = `Temperature: ${fahrenheit} °F`;
    } else {
        document.getElementById('temperature-result').textContent = 'Please enter a valid temperature in Celsius.';
    }
}
