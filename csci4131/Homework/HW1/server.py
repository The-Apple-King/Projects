from http.server import BaseHTTPRequestHandler, HTTPServer

def server(url):
    # if there is a ? we only take the path else take the whole thing
    endOfPath = url.find('?')
    if(endOfPath != -1):
        path = url[0:endOfPath]
    else:
        path = url

    # navigate to the correct page based on url
    if(path == "/contact"):
        print("contact", path)
        return open("contactform.html").read()
    elif(path == "/testimonies"):
        print("testimonies", path)
        return open("testimonies.html").read()
    elif(path == "/main" or (path == "/" and len(path) == 1)):
        print("mainpage", path)
        return open("mainpage.html").read()
    else:
        print("404", path)
        return open("404.html").read()
    

# You shouldn't need to change content below this. It would be best if you just left it alone.

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        # Call the student-edited server code.
        message = server(self.path)
        
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
        self.send_header("Content-Type", "text/html; charset=utf-8")
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
