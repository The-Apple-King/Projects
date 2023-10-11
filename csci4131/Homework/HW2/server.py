from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib

contacts = [
    {"name": "Owen", "email": "swear041@umn.edu", "date": "2023-10-11", "dropdown": "Seller", "subscribe": "on"},
    {"name": "test", "email": "test@umn.edu", "date": "2023-10-11", "dropdown": "Buyer", "subscribe": "off"}
    ]

def server(url):
    endOfPath = url.find('?')
    parameters = ""
    if(endOfPath != -1):
        path = url[0:endOfPath]
        parameters = url[endOfPath+1:]
        print("parameters", parameters)
    else:
        path = url

    # navigate to the correct page based on url
    if(path == "/contact"):
        print("contact", path)
        #deal with url parameters
        if(parameters != ""):
            print("\nwe have parameters\n")
            parameters = parameters.split("&")
            print(parameters)
            newContact = {}
            for param in parameters:
                param = urllib.parse.unquote(param, encoding='utf-8', errors='replace')
                curParam = param.split("=")
                newContact[curParam[0]] = curParam[1]
            if len(parameters) <= 5:
                newContact["subscribe"] = "off"
            contacts.append(newContact)

    
        return open("static/html/contactform.html").read(), "text/html"
    elif(path == "/testimonies"):
        print("testimonies", path)
        return open("static/html/testimonies.html").read(), "text/html"
    elif(path == "/main" or (path == "/" and len(path) == 1)):
        print("mainpage", path)
        return open("static/html/mainpage.html").read(), "text/html"
    elif(path == "/admin/contactlog"):
        print("admin/contactlog", path)
        return createAdmin(), "text/html"
    elif(path == "/css/main.css"):
        print("css", "css/main.css")
        return open("static/css/main.css").read(), "text/css"
    elif(path == "/images/main"):
        return open("static/images/salesman.jpg", "rb").read(), "image/jpeg"
    else:
        print("404", path)
        return open("static/html/404.html").read(), "text/html"
    
def createAdmin():
    # Start building the HTML content
    html_content = """
    <!DOCTYPE html>
    <html>
    <head>
        <title>The Snake Oil Salesman</title>
        <meta charset="UTF-8">
        <link rel="stylesheet" href="../css/main.css">
        <style>
            @import url('https://fonts.googleapis.com/css2?family=Finger+Paint&display=swap');
        </style>
    </head>
    <body>
        <div class="navbar">
            <a href="/main">Home</a>
            <a href="/contact">Contact</a>
            <a href="/testimonies">Testimonies</a>
            <a href="/admin/contactlog">Contact Log</a>
        </div> 
        <h1>Contact Log</h1>
        <table>
            <tr>
                <th>Name</th>
                <th>Email</th>
                <th>Date</th>
                <th>Buyer or Seller</th>
                <th>Subscribed to Newsletter</th>
            </tr>
    """

    # Populate the table with contact data
    for contact in contacts:
        # Customize the checkbox label as needed
        checkbox_label = "Yes" if contact["subscribe"] == "on" else "No"

        # Create a mailto link for the email field
        email_link = f'<a href="mailto:{contact["email"]}">{contact["email"]}</a>'

        # Add a row for each contact
        html_content += f"""
            <tr>
                <td>{contact["name"]}</td>
                <td>{email_link}</td>
                <td>{contact["date"]}</td>
                <td>{contact["dropdown"]}</td>
                <td>{checkbox_label}</td>
            </tr>
        """

    # Close the HTML content
    html_content += """
        </table>
    </body>
    </html>
    """
    print(contacts)
    return html_content

# You shouldn't need to change content below this. It would be best if you just left it alone.

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        # Call the student-edited server code.
        message, content_type = server(self.path)

        # Convert the return value into a byte string for network transmission
        if type(message) == str:
            message = bytes(message, "utf8")

        # prepare the response object with minimal viable headers.
        self.protocol_version = "HTTP/1.1"
        # Send response code
        self.send_response(200)
        # Send headers
        # Note -- this would be binary length, not string length
        self.send_header("Content-Length", len(message))
        self.send_header("Content-Type", content_type)
        self.send_header("X-Content-Type-Options", "nosniff")
        self.end_headers()

        # Send the file.
        self.wfile.write(message)
        return

def run():
    PORT = 4131
    print(f"Starting server http://localhost:{PORT}/")
    server = ('', PORT)
    httpd = HTTPServer(server, RequestHandler)
    httpd.serve_forever()
run()
