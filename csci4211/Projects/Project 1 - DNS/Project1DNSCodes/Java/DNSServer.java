/* Spring 2023 CSci4211: Introduction to Computer Networks
** This program serves as the server of DNS query.
** Written in Java. */

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Random;
import java.util.TreeMap;

class DNSServer {
	public static void main(String[] args) throws Exception {
		int port = 9889;
		ServerSocket sSock = null;

		try {
			sSock = new ServerSocket(port); // Try to open server socket 5001.
		} catch (Exception e) {
			System.out.println("Error: cannot open socket");
			System.exit(1); // Handle exceptions.
		}

		System.out.println("Server is listening...");
		new monitorQuit().start(); // Start a new thread to monitor exit signal.

		while (true) {
			new dnsQuery(sSock.accept()).start();
		}
	}
}

class dnsQuery extends Thread {
	Socket sSock = null;
    	dnsQuery(Socket sSock) {
    	this.sSock = sSock;

    }
    public String IPselection(String[] ipList){
    //checking the number of IP addresses in the cache
	//if there is only one IP address, return the IP address
	//if there are multiple IP addresses, select one and return.
	////optional: return the IP address according to the Ping value for better performance (lower latency)
		if (ipList.length >= 1) {
			return ipList[0];
		}
		return null;
    }
	@Override public void run(){
	BufferedReader inputStream;
        PrintWriter outStream;
        try {
			//Open an input stream and an output stream for the socket
			inputStream = new BufferedReader(new InputStreamReader(sSock.getInputStream()));
			outStream = new PrintWriter(sSock.getOutputStream(), true);


			//Read requested query from socket input stream
			String hostname = inputStream.readLine();


            try {
				//open up writer and readers for files
				PrintWriter csvLogFile = new PrintWriter(new FileWriter("dns-server-log.csv", true));
				PrintWriter cacheWriter = new PrintWriter(new FileWriter("DNS_mapping.txt", true));
				BufferedReader cacheReader = new BufferedReader(new FileReader("DNS_mapping.txt"));

				//create a treemap with a key and a list of ipaddress for cache
				String line = "";
				TreeMap<String, ArrayList<String>> dictionary = new TreeMap<String, ArrayList<String>>();
				while ((line = cacheReader.readLine()) != null) {
					//while not at end of file save hostname and ip in string array
					String keyPair[] = line.split(",");
					//if hostname already exists add it to the list
					if (dictionary.containsKey(keyPair[0])) {
						dictionary.get(keyPair[0]).add(keyPair[1]);
					}
					//if hostname is new create a new array for its ipaddress
					else{
						dictionary.put(keyPair[0], new ArrayList<String>());
						dictionary.get(keyPair[0]).add(keyPair[1]);
					}
				}

				//if hostname is in the dictionary print to all required streams
				if(dictionary.containsKey(hostname)){
					String[] ipList = dictionary.get(hostname).toArray(new String[0]);
					String ip = IPselection(ipList);
					csvLogFile.println(hostname + ", " + ip + ", " + "CACHED");
					outStream.println(hostname + ":" + ip + ":" + "CACHED");
					System.out.println(hostname + ":" + ip + ":" + "CACHED");

					//else we attempt to find an ipaddress for the hostname
				}else{
					String ipAddress;
					try {
						InetAddress inetAddress = InetAddress.getByName(hostname);
						ipAddress = inetAddress.getHostAddress();
					} catch (UnknownHostException e) {
						ipAddress = "Host not found";
					}
					//then print to all required streams
					csvLogFile.println(hostname + ", " + ipAddress + ", " + "API");
					cacheWriter.println(hostname + "," + ipAddress);
					outStream.println(hostname + ":" + ipAddress + ":" + "API");
					System.out.println(hostname + ":" + ipAddress + ":" + "API");
				}

				//close required streams
				cacheReader.close();
				cacheWriter.close();
				csvLogFile.close();
            } catch (Exception e) {
                System.out.println("exception: " + e);
            }
	//Close the input and output streams.
			inputStream.close();
			outStream.close();


        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Host not found.\n" + e);
        }
	}
}

class monitorQuit extends Thread {
	@Override
	public void run() {
		BufferedReader inFromClient = new BufferedReader(new InputStreamReader(System.in)); // Get input from user.
		String st = null;
		while(true){
			try{
				st = inFromClient.readLine();
			} catch (IOException e) {
			}
            if(st.equalsIgnoreCase("exit")){
                System.exit(0);
            }
        }
	}
}
