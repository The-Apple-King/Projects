from __future__ import annotations
from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib

contacts = [
    {"name": "Owen", "email": "swear041@umn.edu", "date": "2023-10-11", "dropdown": "Seller", "seller": "on"},
    {"name": "test", "email": "test@umn.edu", "date": "2023-10-11", "dropdown": "Buyer", "seller": "off"}
    ]

# PUT YOUR GLOBAL VARIABLES AND HELPER FUNCTIONS HERE.
# It is not required, but is is strongly recommended that you write a function to parse form data out of the URL, and a second function for generating the contact log page html.

def server_GET(url: str) -> tuple[str | bytes, str, int]:
    """
    url is a *PARTIAL* URL. If the browser requests `http://localhost:4131/contact?name=joe`
    then the `url` parameter will have the value "/contact?name=joe". (so the schema and
    authority will not be included, but the full path, any query, and any anchor will be included)

    This function is called each time another program/computer makes a request to this website.
    The URL represents the requested file.

    This function should return three values (string or bytes, string, int) in a list or tuple. The first is the content to return
    The second is the content-type. The third is the HTTP Status Code for the response
    """
    #YOUR CODE GOES HERE!

    endOfPath = url.find('?')
    if(endOfPath != -1):
        path = url[0:endOfPath]
    else:
        path = url

    # navigate to the correct page based on url
    if(path == "/contact"):
        print("contact", path)
        return open("static/html/contactform.html").read(), "text/html", 200
    elif(path == "/testimonies"):
        print("testimonies", path)
        return open("static/html/testimonies.html").read(), "text/html", 200
    elif(path == "/main" or (path == "/" and len(path) == 1)):
        print("mainpage", path)
        return open("static/html/mainpage.html").read(), "text/html", 200
    elif(path == "/admin/contactlog"):
        print("admin/contactlog", path)
        return createAdmin(), "text/html", 200
    elif(path == "/css/main.css"):
        print("css", "css/main.css")
        return open("static/css/main.css").read(), "text/css", 200
    elif(path == "/css/main.dark.css"):
        print("css", "css/main.dark.css")
        return open("static/css/main.dark.css").read(), "text/css", 200
    elif(path == "/images/main"):
        return open("static/images/salesman.jpg", "rb").read(), "image/jpeg", 200
    elif(path == "/js/main.js"):
        return open("static/js/main.js").read(), "text/javascript", 200
    elif(path == "/js/table.js"):
        return open("static/js/table.js").read(), "text/javascript", 200
    elif(path == "/js/contact.js"):
        return open("static/js/contact.js").read(), "text/javascript", 200
    else:
        print("404", path)
        return open("static/html/404.html").read(), "text/html", 404

def server_POST(url: str, body: str) -> tuple[str | bytes, str, int]:
    """
    url is a *PARTIAL* URL. If the browser requests `http://localhost:4131/contact?name=joe`
    then the `url` parameter will have the value "/contact?name=joe". (so the schema and
    authority will not be included, but the full path, any query, and any anchor will be included)

    This function is called each time another program/computer makes a POST request to this website.

    This function should return three values (string or bytes, string, int) in a list or tuple. The first is the content to return
    The second is the content-type. The third is the HTTP Status Code for the response
    """

    print("\n\nurl: ", url, "body: ", body, "\n\n" )
    

    if(url == "/contact"):
    #deal with url parameters
        if(body != ""):
            newContact = {}
            if "seller" not in body:
                newContact["seller"] = "off"
            if "name" in body and "&email" in body and "&date" in body and "&dropdown" in body:
                body = body.split("&")
                for param in body:
                    param = urllib.parse.unquote(param, encoding='utf-8', errors='replace')
                    curParam = param.split("=")
                    newContact[curParam[0]] = curParam[1]
                contacts.append(newContact)
            else:
                #if something wrong
                return errorPage(), "text/html", 400
        else:
            return errorPage(), "text/html", 400

        print("contact", url)
        return success(), "text/html", 201
    else:
        print("404", url)
        return open("static/html/404.html").read(), "text/html", 404

def success():
    html_content = """
    <!DOCTYPE html>
        <head>
            <title>Error Page not found</title>
            <meta charset="UTF-8">
            <link rel="stylesheet" href="../css/main.css">
            <link rel="stylesheet" href="../css/main.dark.css">
            <script src="../js/main.js"></script>
            <style>
                @import url('https://fonts.googleapis.com/css2?family=Finger+Paint&display=swap');
            </style>
        </head>
        <body>
            <div class="navbar">
                <a href="/main">Home</a>
                <a href="/contact">Order</a>
                <a href="/testimonies">Testimonies</a>
                <a href="/admin/contactlog">Order Log</a>
                <a id="theme-toggle" href="">Dark Mode Toggle</a>
            </div>
            <h1>You Have Successfully Bought Snake Oil!</h1>
            <p>If you would like to buy more <a href="mainpage.html">click here</a> to return to the main page.</p>
        </body>
    </html>"""
    return html_content

def errorPage():
    html_content = """
    <!DOCTYPE html>
        <head>
            <title>Error Page not found</title>
            <meta charset="UTF-8">
            <link rel="stylesheet" href="../css/main.css">
            <link rel="stylesheet" href="../css/main.dark.css">
            <script src="../js/main.js"></script>
            <style>
                @import url('https://fonts.googleapis.com/css2?family=Finger+Paint&display=swap');
            </style>
        </head>
        <body>
            <div class="navbar">
                <a href="/main">Home</a>
                <a href="/contact">Order</a>
                <a href="/testimonies">Testimonies</a>
                <a href="/admin/contactlog">Order Log</a>
                <a id="theme-toggle" href="">Dark Mode Toggle</a>
            </div>
            <h1>400 Error Something Went Wrong</h1>
            <p>If you would like to buy some of my snake oil <a href="mainpage.html">click here</a> to return to the main page.</p>
        </body>
    </html>"""
    return html_content
     

def createAdmin():
    # Start building the HTML content
    html_content = """
    <!DOCTYPE html>
    <html>
    <head>
        <title>The Snake Oil Salesman</title>
        <meta charset="UTF-8">
        <link rel="stylesheet" href="../css/main.css">
        <link rel="stylesheet" href="../css/main.dark.css">
        <script src="../js/main.js"></script>
        <script src="../js/table.js"></script>
        <style>
            @import url('https://fonts.googleapis.com/css2?family=Finger+Paint&display=swap');
        </style>
    </head>
    <body>
        <div class="navbar">
            <a href="/main">Home</a>
            <a href="/contact">Order</a>
            <a href="/testimonies">Testimonies</a>
            <a class="active" href="/admin/contactlog">Order Log</a>
            <a id="theme-toggle" href="#">Dark Mode Toggle</a>
        </div> 
        <h1>Contact Log</h1>
        <table id="table">
            <tr>
                <th>Name</th>
                <th>Email</th>
                <th>Time Until Delivery</th>
                <th>Amount</th>
                <th>Distributor</th>
            </tr>
    """

    # Populate the table with contact data
    row = 0
    for contact in contacts:
        # Customize the checkbox label as needed
        checkbox_label = "Yes" if contact["seller"] == "on" else "No"

        # Create a mailto link for the email field
        email_link = f'<a href="mailto:{contact["email"]}">{contact["email"]}</a>'

        # Add a row for each contact
        html_content += f"""
            <tr>
                <td>{contact["name"]}</td>
                <td>{email_link}</td>
                <td><div class="date">{contact["date"]}</div><div class="countdown"><div></td>
                <td>{contact["dropdown"]}</td>
                <td>{checkbox_label}</td>
                <td><button onclick="deleteRow(this)">Delete</button></td>
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
    def do_POST(self):
        # Read the content-length header sent by the BROWSER
        content_length = int(self.headers.get('Content-Length',0))
        # read the data being uploaded by the BROWSER
        body = self.rfile.read(content_length)
        # we're making some assumptions here -- but decode to a string.
        body = str(body, encoding="utf-8")

        message, content_type, response_code = server_POST(self.path, body)

        # Convert the return value into a byte string for network transmission
        if type(message) == str:
            message = bytes(message, "utf8")

        # prepare the response object with minimal viable headers.
        self.protocol_version = "HTTP/1.1"
        # Send response code
        self.send_response(response_code)
        # Send headers
        # Note -- this would be binary length, not string length
        self.send_header("Content-Length", len(message))
        self.send_header("Content-Type", content_type)
        self.send_header("X-Content-Type-Options", "nosniff")
        self.end_headers()

        # Send the file.
        self.wfile.write(message)
        return

    def do_GET(self):
        # Call the student-edited server code.
        message, content_type, response_code = server_GET(self.path)

        # Convert the return value into a byte string for network transmission
        if type(message) == str:
            message = bytes(message, "utf8")

        # prepare the response object with minimal viable headers.
        self.protocol_version = "HTTP/1.1"
        # Send response code
        self.send_response(response_code)
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
    server = ("", PORT)
    httpd = HTTPServer(server, RequestHandler)
    httpd.serve_forever()


run()