
/*HTTP Parser Assessment
Author: Vasu Vandan Kodakandla
Last Modified Date: 26-06-2022*/

#include <iostream>
#include<string>
#include<map>

using namespace std;

const    string sInvalidStatusLine = "Invalid Status Line";
const    string sHeaderKeyNotFound = "Header Key Not Found";

class HttpParser
{
    public:

        int iNbrValidHeaders;
        int iNbrInvalidHeaders;

        string sHttpResp ;
        string sHttpVerNbr ;
        string sStatusCode;
        string sStatusMsg;
        string sResp;

        map<string, string> headerMap;

    public:
        //constructor to intialize HttpParser member variables
        HttpParser()
        {
            sHttpResp = "";
            sHttpVerNbr = "";
            sStatusCode = "";
            sStatusMsg = "";
            sResp = "";

            iNbrValidHeaders = 0;
            iNbrInvalidHeaders = 0;
        }

        //HttpParser destructor
        ~HttpParser() {}

        void validateHttpStatusHeader(string headerLine)
        {

            sHttpResp = headerLine.substr(0,7);
            sHttpVerNbr = headerLine[7];
            sStatusCode = headerLine.substr(9,3);
            sStatusMsg = headerLine.substr(13);

            //Invalid status line if respective indexes are not digits and respective indexes are not spaces;
            //Header line 1 is invalid if it fall in any below rules
            //1. If HTTP req is not starting with "HTTP/1."
            //2. If Indexes 7,9,10,11 are not digits
            //3. If Indexes 8 and 12 are not spaces.

            if( sHttpResp !="HTTP/1."||
                !isdigit(headerLine[7]) || !isdigit(headerLine[9]) || !isdigit(headerLine[10]) || !isdigit(headerLine[11]) || 
                !isspace(headerLine[8])  || !isspace(headerLine[12]) )
            {
                    sResp = sInvalidStatusLine;
            }
        }

        void validateOtherHeaders(string headerLine)
        {
            int pos = headerLine.find(":");
            string sHdrKey = headerLine.substr(0,pos);
            string sHdrValue = headerLine.substr(pos + 2);

            //Invalid header line if message follows below any rules
            //1. If headerline is not containing :
            //2. If Header key or header value is empty
            //3. If space is not available after first charcter :
            if(pos == -1 ||sHdrKey.empty() || sHdrValue.empty() || !isspace(headerLine[pos+1]) )
            {
                iNbrInvalidHeaders++;
            }
            else
            {
                iNbrValidHeaders++;

                //Set headerkey and headervalue
                headerMap[sHdrKey] = sHdrValue;
            }
        }   

        //Return header value based on header key
        string getHeaderValue(string sKey)
        {
            if (headerMap.find(sKey) == headerMap.end()) 
            {
                return sHeaderKeyNotFound;
            }
            else
                return headerMap[sKey];
        }
};

int main() 
{
    int  headerNumber = 1;
    string headerLine = "";
    HttpParser cHttpReq;

    while (std::getline(std::cin, headerLine))
    {
       if(headerNumber ==1)
       {
           cHttpReq.validateHttpStatusHeader(headerLine);

           if(cHttpReq.sResp == sInvalidStatusLine)
               break;
       }
       else if( headerLine.substr(0,5) == "date: ")
       {
           cHttpReq.iNbrValidHeaders++;
           continue;
       }
       else
       {
            cHttpReq.validateOtherHeaders(headerLine);
       }

       headerNumber++;
    }

    if(cHttpReq.sResp.empty())
    {
        cHttpReq.sResp = "HTTP version: 1." + cHttpReq.sHttpVerNbr  + "\r\n" +
                         "Status: " + cHttpReq.sStatusCode + "\r\n"  +
                         "Number of valid headers: " +  to_string(cHttpReq.iNbrValidHeaders) + "\r\n"  +
                         "Number of invalid headers: " +  to_string(cHttpReq.iNbrInvalidHeaders) + "\r\n" ;
    }

    cout<<cHttpReq.sResp<<endl;

    //cout<<cHttpReq.getHeaderValue("cache-control")<<endl;

    return 0;
}

