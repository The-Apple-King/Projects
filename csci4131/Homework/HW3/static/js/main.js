document.addEventListener("DOMContentLoaded", function () {
    //when loaded
    const themeToggle = document.getElementById("theme-toggle");
    let isDarkMode = localStorage.getItem("darkMode") === "true";
    if(isDarkMode){
    setTheme(isDarkMode);
    }
    
    // when clicked
    themeToggle.addEventListener("click", function () {
        isDarkMode = !isDarkMode;
        setTheme(isDarkMode);
    });
});
  
function setTheme(isDarkMode) {
    let body = document.body;
    
    body.classList.toggle("dark-mode");
    localStorage.setItem("darkMode", isDarkMode);
}