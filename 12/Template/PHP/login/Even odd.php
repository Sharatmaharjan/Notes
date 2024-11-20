<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Even or Odd Checker</title>
</head>
<body>
    <h1>Check if a Number is Even or Odd</h1>
    <form method="post" action="">
        <label for="number">Enter a number:</label>
        <input type="number" id="number" name="number" required>
        <button type="submit">Check</button>
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        // Get the input number
        $number = $_POST['number'];

        // Check if the number is even or odd
        if ($number % 2 == 0) {
            echo "<p>The number <strong>$number</strong> is <strong>Even</strong>.</p>";
        } else {
            echo "<p>The number <strong>$number</strong> is <strong>Odd</strong>.</p>";
        }
    }
    ?>
</body>
</html>
