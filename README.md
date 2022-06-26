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
