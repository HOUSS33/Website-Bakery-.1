document.addEventListener("DOMContentLoaded", function() {
    function isValidEmail(email) {
        // Regular expression for basic email validation
        let emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return emailRegex.test(email);
    }

    // Keep prompting until a valid email is provided or the user cancels
    let email;
    while (true) {
        email = prompt("Please enter your email address:");
        if (email === null) {
            alert("No email address provided.");
            break;
        } else if (isValidEmail(email.trim())) {
            alert("Thank you for providing your email address: " + email.trim());
            break;
        } else {
            alert("Invalid email address. Please enter a valid email.");
        }
    }
});
