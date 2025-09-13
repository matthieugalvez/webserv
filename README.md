# webserv

Webserv is a web server using `select` as a non-blocking client manager and implementing CGIs.


## Installation

Use make to build webserv executable binary.
```bash
make
```


## Launch

Execute the webserv binary with a configuration file (.conf) entered as parameter. If no parameter is provided, webserv will try to configure itself using the `conf_files/ConfigBase.conf` file.
```
webserv [confFile]
```


## Configuration File

Configuration files are identified by the `.conf` filename extension. A default configuration file is provided in the repository.

Each line in the configuration file define an option for the generated server. An option exist inside the scope of either a server or a location.

Servers and locations must be defined as followed:

```
server {
    [serverOption1
    serverOption2
    serverOption3
    ...]
    location <locationPath> {
        [locationOption1
        locationOption2
        locationOption3
        ...]
    }
}
```

### server options

`listen <port>` The port the server will be listening.

`server_name <name>` The server name indication (SNI).

`host <IPAdress>` The IP adress the server will be accessible from.

`error_page <errorNum> <filePath>` The `html` file that will be load by the server on error `<errorNum>`.

### location options

`autoindex <on/off>` If on, server will generate a default index.html file listing this location's files.

`upload_dir <directoryPath>` Define a directory in with uploaded files will be stored.

`cgi <filenameExtension> [binaryName]` Specify a filename extension to treat as CGI inside location. The binary used to execute the cgi script can be provided as option. Otherwise, the server will consider the file as an executable.

`allow_methods [method1 method2 ...]` List HTTP methods allowed in location. Supported methods are `DELETE`, `POST` and `GET`.

`return <HTTPStatusCode> <redirectionURL>` Location send a return response with code `<HTTPStatusCode>` redirecting client toward `<redirectionURL>`.

### options viable in both scopes

These options can be defined in server scope to serv as default for the locations of said server or be overwritten at location scope.

`root <path>` Define root to the relative path of the location.

`index <file>` Define a custom index file for location.

`client_max_body_size <size>` Define the maximum size of client request for location.
