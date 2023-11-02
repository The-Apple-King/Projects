window.addEventListener("load", ()=> {
    const date = document.getElementById("date");
    const dropdown = document.getElementById("dropdown");
    const seller = document.getElementById("seller");

    date.addEventListener("change", CalculatePrice);
    dropdown.addEventListener("change", CalculatePrice);
    seller.addEventListener("change", CalculatePrice);
});
  
function CalculatePrice() {
    const dropdownValue = document.getElementById("dropdown").value;
    const sellerChecked = document.getElementById("seller").checked;
    const selectedDate = new Date(document.getElementById("date").value);

    // default prices
    const prices = {
      "5ml": 10,
      "Gallon": 50,
      "Barrel": 200
    };

    let totalCost = prices[dropdownValue] || 0;
  
    // if a person is a distributor for us already 10% discount
    if (sellerChecked) {
      totalCost *= 0.9; 
    }
  
    const oneWeekFromNow = new Date();
    oneWeekFromNow.setDate(oneWeekFromNow.getDate() + 7);
    // if they buy the snake oil faster, within a week, they get a 15% discount
    if (selectedDate <= oneWeekFromNow) {
        totalCost *= 0.85; 
    }

    const priceElement = document.getElementById("price");
    priceElement.innerText = "$" + totalCost.toFixed(2); 
  }