<?php
session_start();
require 'db.php';

if (!isset($_SESSION['username'])) {
    header("Location: index.php");
    exit();
}

$username = $_SESSION['username'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Profile</title>
    <style>
        body { font-family: Arial, sans-serif; background-color: #f3f3f3; }
        .container { width: 300px; margin: 100px auto; background: #fff; padding: 20px; border-radius: 8px; text-align: center; }
        button { padding: 10px; background-color: #FF5733; color: white; border: none; border-radius: 5px; cursor: pointer; }
    </style>
</head>
<body>
<div class="container">
    <h2>Welcome, <?php echo htmlspecialchars($username); ?>!</h2>
    <p>You have successfully logged in.</p>
    <form method="POST" action="logout.php">
        <button type="submit">Logout</button>
    </form>
</div>
</body>
</html>
