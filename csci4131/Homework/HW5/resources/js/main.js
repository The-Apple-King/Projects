document.addEventListener("DOMContentLoaded", function () {
    //when loaded
    const themeToggle = document.getElementById("theme-toggle");
    let isDarkMode = localStorage.getItem("darkMode") === "true";
    if(isDarkMode){
    toggle_style(isDarkMode);
    }
    
    // when clicked
    themeToggle.addEventListener("click", function () {
        isDarkMode = !isDarkMode;
        toggle_style(isDarkMode);
    });
});
  
function toggle_style(isDarkMode) {
    let body = document.body;
    
    body.classList.toggle("dark-mode");
    localStorage.setItem("darkMode", isDarkMode);
}


document.addEventListener("DOMContentLoaded", function() {
    // only request every second if the sales banner is on the page
    if(document.getElementById("salesBanner") != null)
        handle_banner(document.getElementById("salesBanner"));
});

async function handle_banner(banner) {
    setInterval(async function() {
        const response = await fetch("/api/sale");
        if (response.ok) {
            data = await response.json()
            banner.innerText = data.message;
        }
    }, 1000);
}