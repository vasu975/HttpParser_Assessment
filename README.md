# HTTP Parser Assessment
This repository consists of files related to HTTP Parser Assessment.

## Aim
Developing HTTP parser in C++ to parse an HTTP response status line and headers

## Introduction 

- Each line in the HTTP response should be terminated with a CR LF sequence
- The HTTP response will begin with a status line, followed by zero or more header
lines
- A status line consists of the HTTP version, status code, and reason phrase, each
separated by a space
    1. The HTTP version is the case-sensitive string “HTTP/” followed by a
    major and minor version (e.g. HTTP/1.1)
    2. The status code is a 3 digit numeric code
    3. The reason phrase is a string describing the status code
- A header line consists of a header name, followed by “: “, followed by the header
value
    1. A header name can contain any letter, digit, and the character “-”
    2. A header value can contain any visible/printable ASCII character

The input would be a contiguous buffer of data with the header part of an HTTP
response. The parser should extract the HTTP version and status code from the status
line, and parse each header line to determine if the header is valid according to the rules
described above.
- The parser should store the valid headers, and provide a way to look up a header value
by name.
- The parser should output the HTTP version and status code, as well as the number of
valid and invalid headers. If the response does not have a valid status line, then the
parser can output an error message and abort parsing.


## Methodology 

1. Implemented Class HttpParser in C++.

2. It maintains below member varaiables.
	1. Number of valid Headers
	2. Number of invalid Headers
	3. HTTP Response: It contains start information. Example: HTTP/1. 
	4. Http Version Number: 
	5. Status Code: Response Status Code
	6. Status Message: Response Status Message
	7. Output Response: Output of HTTP Parser program
	8. Header Map: It holds Header key and value
	
3. It contains below methods
	1. validateHttpStatusHeader :  It Validates first line of HTTP response
	2. validateOtherHeaders :  It validates all header line and stores header keys and values in header map.
	3. getHeaderValue : Returns header value of header key.

## Future Work 
- Validating all header keys and values with detailed specifications.
- Adding test cases based on different type of HTTP responses and modify code.


Execution
- Execute code by copy pasting  code in coding minutes online ide.
   https://ide.codingminutes.com/
- It is as follows in below screensot.
![image](https://user-images.githubusercontent.com/60496195/166647199-236fe68a-a066-485a-b81f-17799c9ecbb2.png)

## References
* Datatracker documentation- https://datatracker.ietf.org/doc/html/rfc7230#section-3

