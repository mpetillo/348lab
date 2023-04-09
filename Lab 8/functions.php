<html>
<body>
    <style>
        table, tr, td {
            border: 1px solid black;
            border-collapse: collapse;
        }
    </style>
<table>
    <tr>
        <td></td>
        <?php for ($i = 1; $i <= $_POST["size"]; $i++){
            echo "<td>$i</td>"
        ?>
    </tr>
    <?php for ($i = 1; $i <= $_POST["size"]; $i++){
        echo "<tr>"
        echo "<td>" . $i . "</td>"
        for ($j = 1; $j <= $_POST["size"]; $j++){
            echo "<td>" . $i*$j . "</td>"
        }
        echo "</tr>"
    }?>
</table>
</body>
</html> 