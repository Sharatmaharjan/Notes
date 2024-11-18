<?php
session_start();
require 'db.php';

if (isset($_SESSION['username'])) {
    header("Location: profile.php");
    exit();
}

$message = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $conn->real_escape_string($_POST['username']);
    $password = $conn->real_escape_string($_POST['password']);

    // Query to check credentials
    $query = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";
    $result = $conn->query($query);

    if ($result && $result->num_rows === 1) {
        $user = $result->fetch_assoc();
        $_SESSION['username'] = $user['username'];
        header("Location: profile.php");
        exit();
    } else {
        $message = "Invalid username or password!";
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <style>
        body { font-family: Arial, sans-serif; background-color: #f3f3f3; }
        .container { width: 300px; margin: 100px auto; background: #fff; padding: 20px; border-radius: 8px; }
        input { width: 100%; padding: 10px; margin: 10px 0; }
        button { width: 100%; padding: 10px; background-color: #007BFF; color: white; border: none; border-radius: 5px; }
        .message { color: red; font-size: 0.9em; margin-top: 10px; }
    </style>
</head>
<body>
<div class="container">
    <h2>Login</h2>
    <form method="POST" action="">
        <input type="text" name="username" placeholder="Username" required>
        <input type="password" name="password" placeholder="Password" required>
        <button type="submit">Login</button>
        <?php if ($message): ?>
            <p class="message"><?php echo htmlspecialchars($message); ?></p>
        <?php endif; ?>
    </form>
</div>
</body>
</html>
