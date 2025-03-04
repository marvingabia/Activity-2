
api.php
<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "integrative3";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die(json_encode(["status" => "error", "message" => "Connection failed: " . $conn->connect_error]));
}

$data = json_decode(file_get_contents("php://input"), true);

if (!empty($data["name"])) {
  
    $name = $conn->real_escape_string($data["name"]);
    $value= $conn->real_escape_string($data["value"]);
   

    $sql = "INSERT INTO unit3 ( name,value) VALUES ( '$name', '$value' )";

    if ($conn->query($sql) === TRUE) {
        echo json_encode(["status" => "success", "message" => "sensor data added successfully"]);
    } else {
        echo json_encode(["status" => "error", "message" => "Error: " . $conn->error]);
    }
} else {
    echo json_encode(["status" => "error", "message" => "Invalid input"]);
}

$conn->close();

?>








