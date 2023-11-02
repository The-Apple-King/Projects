from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib #Only for parse.unquote and parse.unquote_plus.
import json
import base64
from typing import Union, Optional
import re
# If you need to add anything above here you should check with course staff first.

contacts = []
next_id = 0
sale_text = "test"
sale = True
valid_username = "admin"
valid_password = "password"

# The method signature is a bit "hairy", but don't stress it -- just check the documentation below.
def server(method: str, url: str, body: Optional[str], headers: dict[str, str]) -> tuple[Union[str, bytes], int, dict[str, str]]:    
    global next_id
    global sale
    global sale_text
    """
    method will be the HTTP method used, for our server that's GET, POST, DELETE
    url is the partial url, just like seen in previous assignments
    body will either be the python special None (if the body wouldn't be sent)
         or the body will be a string-parsed version of what data was sent.
    headers will be a python dictionary containing all sent headers.

    This function returns 3 things:
    The response body (a string containing text, or binary data)
    The response code (200 = ok, 404=not found, etc.)
    A _dictionary_ of headers. This should always contain Content-Type as seen in the example below.
    """
    # Parse URL -- this is probably the best way to do it. Delete if you want.
    url, *parameters = url.split("?", 1)
    print("URL: ", url, "\n parameters: ", parameters)

    # And another freebie -- the 404 page will probably look like this.
    # Notice how we have to be explicit that "text/html" should be the value for
    # header: "Content-Type" now?]
    # I am sorry that you're going to have to do a bunch of boring refactoring.
    if(method == "GET"):
        if(url == "/contact"):
            print("contact", url)
            return open("static/html/contactform.html").read(), 200, {"Content-Type": "text/html; charset=utf-8"}
        elif(url == "/testimonies"):
            print("testimonies", url)
            return open("static/html/testimonies.html").read(), 200, {"Content-Type": "text/html; charset=utf-8"}
        elif(url == "/main" or (url == "/" and len(url) == 1)):
            print("mainpage", url)
            return open("static/html/mainpage.html").read(), 200, {"Content-Type": "text/html; charset=utf-8"}
        elif(url == "/admin/contactlog"):
            if "Authorization" not in headers:
                return "Unauthorized. Please provide credentials.", 401, {"WWW-Authenticate": 'Basic realm="User Visible Realm"'}
            elif not authenticate(headers):
                return "Invalid credentials", 403, {"Content-Type": "text/plain; charset=utf-8"}
            return createAdmin(), 200, {"Content-Type": "text/html; charset=utf-8"}
        elif(url == "/css/main.css"):
            print("css", "css/main.css")
            return open("static/css/main.css").read(), 200, {"Content-Type": "text/css; charset=utf-8"}
        elif(url == "/css/main.dark.css"):
            print("css", "css/main.dark.css")
            return open("static/css/main.dark.css").read(), 200, {"Content-Type": "text/css; charset=utf-8"}
        elif(url == "/images/main"):
            return open("static/images/salesman.jpg", "rb").read(), 200, {"Content-Type": "image/jpeg; charset=utf-8"}
        elif(url == "/js/main.js"):
            return open("static/js/main.js").read(), 200, {"Content-Type": "text/javascript; charset=utf-8"}
        elif(url == "/js/table.js"):
            return open("static/js/table.js").read(), 200, {"Content-Type": "text/javascript; charset=utf-8"}
        elif(url == "/js/contact.js"):
            return open("static/js/contact.js").read(), 200, {"Content-Type": "text/javascript; charset=utf-8"}
        elif(url == "/api/sale"):
            return f'{{"active": {str(sale).lower()}, "message": "{sale_text}"}}', 200, {"Content-Type": "application/json; charset=utf-8"}
        else:
            return open("static/html/404.html").read(), 404, {"Content-Type": "text/html; charset=utf-8"}

    elif (method == "POST"):
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
                newContact["id"] = next_id
                next_id += 1
            else:
                return errorPage(), 200, {"Content-Type": "text/html; charset=utf-8"}

            print("contact", url)
            return success(), 201, {"Content-Type": "text/html; charset=utf-8"}
        elif(url == "/api/sale"):
            if "Authorization" not in headers:
                return "Unauthorized. Please provide credentials.", 401, {"WWW-Authenticate": 'Basic realm="User Visible Realm"'}
            elif not authenticate(headers):
                return "Invalid credentials", 403, {"Content-Type": "text/plain; charset=utf-8"}
            try:
                if "Content-Type" not in headers or headers["Content-Type"] != "application/json":
                    return "Bad Request: Content-Type must be 'application/json'.", 400, {"Content-Type": "text/plain; charset=utf-8"}
                    
                request_data = json.loads(body)

                if "message" in request_data:
                    sale_text = request_data["message"]
                    sale = True
                    return "Success", 200, {"Content-Type": "text/plain; charset=utf-8"}
                else:
                    return "Bad Request: The request JSON must contain a 'message' key.", 400, {"Content-Type": "text/plain; charset=utf-8"}
            except json.JSONDecodeError:
                return "Bad Request: Invalid JSON in the request body.", 400, {"Content-Type": "text/plain; charset=utf-8"}
        else:
            print("404", url)
            return open("static/html/404.html").read(), 404, {"Content-Type": "text/html; charset=utf-8"}
    elif(method == "DELETE"):
        if(url == "/api/contact"):
            if "Authorization" not in headers:
                return "Unauthorized. Please provide credentials.", 401, {"WWW-Authenticate": 'Basic realm="User Visible Realm"'}
            elif not authenticate(headers):
                return "Invalid credentials", 403, {"Content-Type": "text/plain; charset=utf-8"}
            try:
                if "Content-Type" not in headers or headers["Content-Type"] != "application/json":
                    return "Invalid Content-Type header. Please include 'Content-Type: application/json'", 400, {"Content-Type": "text/plain; charset=utf-8"}
                
                data = json.loads(body)
                
                if "id" not in data:
                    return "Missing 'id' property in the JSON data", 400, {"Content-Type": "text/plain; charset=utf-8"}
                
                contact_to_delete = None
                for contact in contacts:
                    if contact["id"] == data["id"]:
                        contact_to_delete = contact
                        contacts.remove(contact_to_delete)
                        return "Contact deleted successfully", 200, {"Content-Type": "text/plain; charset=utf-8"}              
                return "Contact with the specified ID not found", 200, {"Content-Type": "text/plain; charset=utf-8"}
                
            except json.JSONDecodeError:
                return "Invalid JSON data in the request body", 400, {"Content-Type": "text/plain; charset=utf-8"}
        elif(url == "/api/sale"):
            sale = False
            sale_text = ""
            return "deleted sale banner text", 200, {"Content-Type": "text/plain; charset=utf-8"}
        else:
            return open("static/html/404.html").read(), 404, {"Content-Type": "text/html; charset=utf-8"}



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
                <a id="theme-toggle" href="">Dark Mode</a>
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
                <a id="theme-toggle" href="">Dark Mode</a>
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
            <a id="theme-toggle" href="#">Dark Mode</a>
        </div> 
        <div class="bannerControl">
            <input type="text" id="newBanner">
            <div>
                <button onclick="setBanner()">Set</button>
                <button onclick="deleteBanner()">Delete</button>
            </div>
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
                <td><button onclick="deleteRow(this, {contact["id"]})">Delete</button></td>
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

def authenticate(headers: dict) -> bool:
    if "Authorization" in headers:
        auth_header = headers["Authorization"]
        encoded_credentials = auth_header.split(" ")[1]
        decoded_credentials = base64.b64decode(encoded_credentials).decode("utf-8")
        username, password = decoded_credentials.split(":")

        return username == valid_username and password == valid_password
    return False


# You shouldn't need to change content below this. It would be best if you just left it alone.


class RequestHandler(BaseHTTPRequestHandler):
    def c_read_body(self):
        # Read the content-length header sent by the BROWSER
        content_length = int(self.headers.get("Content-Length", 0))
        # read the data being uploaded by the BROWSER
        body = self.rfile.read(content_length)
        # we're making some assumptions here -- but decode to a string.
        body = str(body, encoding="utf-8")
        return body

    def c_send_response(self, message, response_code, headers):
        # Convert the return value into a byte string for network transmission
        if type(message) == str:
            message = bytes(message, "utf8")
        
        # Send the first line of response.
        self.protocol_version = "HTTP/1.1"
        self.send_response(response_code)
        
        # Send headers (plus a few we'll handle for you)
        for key, value in headers.items():
            self.send_header(key, value)
        self.send_header("Content-Length", len(message))
        self.send_header("X-Content-Type-Options", "nosniff")
        self.end_headers()

        # Send the file.
        self.wfile.write(message)
        

    def do_POST(self):
        # Step 1: read the last bit of the request
        try:
            body = self.c_read_body()
        except Exception as error:
            # Can't read it -- that's the client's fault 400
            self.c_send_response("Couldn't read body as text", 400, {'Content-Type':"text/plain"})
            raise
                
        try:
            # Step 2: handle it.
            message, response_code, headers = server("POST", self.path, body, self.headers)
            # Step 3: send the response
            self.c_send_response(message, response_code, headers)
        except Exception as error:
            # If your code crashes -- that's our fault 500
            self.c_send_response("The server function crashed.", 500, {'Content-Type':"text/plain"})
            raise
        

    def do_GET(self):
        try:
            # Step 1: handle it.
            message, response_code, headers = server("GET", self.path, None, self.headers)
            # Step 3: send the response
            self.c_send_response(message, response_code, headers)
        except Exception as error:
            # If your code crashes -- that's our fault 500
            self.c_send_response("The server function crashed.", 500, {'Content-Type':"text/plain"})
            raise


    def do_DELETE(self):
        # Step 1: read the last bit of the request
        try:
            body = self.c_read_body()
        except Exception as error:
            # Can't read it -- that's the client's fault 400
            self.c_send_response("Couldn't read body as text", 400, {'Content-Type':"text/plain"})
            raise
        
        try:
            # Step 2: handle it.
            message, response_code, headers = server("DELETE", self.path, body, self.headers)
            # Step 3: send the response
            self.c_send_response(message, response_code, headers)
        except Exception as error:
            # If your code crashes -- that's our fault 500
            self.c_send_response("The server function crashed.", 500, {'Content-Type':"text/plain"})
            raise



def run():
    PORT = 4131
    print(f"Starting server http://localhost:{PORT}/")
    server = ("", PORT)
    httpd = HTTPServer(server, RequestHandler)
    httpd.serve_forever()


run()
