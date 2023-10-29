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