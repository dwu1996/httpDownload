[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
$WebClient = New-Object System.Net.WebClient
$WebClient.DownloadFile("http://iot.martinintw.com/api/v1/data/12345617","C:\xampp\htdocs\sample.htm")
$WebClient.DownloadFile("http://iot.martinintw.com/api/v1/data/12345619","C:\xampp\htdocs\sample2.htm")