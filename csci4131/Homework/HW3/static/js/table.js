window.addEventListener('load', function() {
    const rows = document.getElementById('table').getElementsByTagName('tr');

    for (let i = 1; i < rows.length; i++) {
        const row = rows[i];
        const rowTimer = this.setInterval(function () {
            var dateDiv = row.cells[2].querySelector(".date");
            var countdownDiv = row.cells[2].querySelector(".countdown");
            
            var endDate = new Date(dateDiv.textContent.trim());

            var distance = endDate - new Date().getTime();
          

            // format countdown from w3 schools
            var days = Math.floor(distance / (1000 * 60 * 60 * 24));
            var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
            var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
            var seconds = Math.floor((distance % (1000 * 60)) / 1000);
          
            countdownDiv.innerHTML = days + "d " + hours + "h " + minutes + "m " + seconds + "s ";
            
            if (distance < 0) {
                countdownDiv.innerHTML = "<b>Passed</b>";
                clearInterval(rowTimer);
            }
        }, 1000);
        row.rowTimer = rowTimer;
    }
});



function deleteRow(button) {
    var row = button.parentNode.parentNode;
    clearInterval(row.rowTimer);
    row.remove();
}