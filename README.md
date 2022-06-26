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
