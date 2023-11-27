window.addEventListener('load', function() {
    const rows = document.getElementById('table').getElementsByTagName('tr');
    if(rows.length == 1 && rows[0].cells.length > 1){
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
    }
});



async function deleteRow(button, id) {
    const options = {
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ id: id }),
    };
    const response = await fetch("/api/contact", options);
    if(response.ok){
        var row = button.parentNode.parentNode;
        clearInterval(row.rowTimer);
        
        var table = row.parentNode;
        row.remove();
        const rows = document.getElementById('table').getElementsByTagName('tr');
        console.log(rows.length);
        if(rows.length == 1){
            var newRow = table.insertRow();
            var cell = newRow.insertCell(0);
            cell.colSpan = 6;
            cell.innerHTML = "No sales available";
        }
    }
}

async function setBanner() {
    const inputElement = document.getElementById("newBanner");
    const inputValue = inputElement.value;

    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({message: inputValue}),
    };
    const response = await fetch("/api/sale", options);
    if(response.ok)
        inputElement.value = "";
}

async function deleteBanner() {
    const options = {
        method: 'DELETE',
    };
    await fetch("/api/sale", options);
}