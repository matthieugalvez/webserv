# webserv

Webserv is a web server using `select` as a non-blocking client manager and implementing CGIs.


## Installation

Use make to build webserv executable binary.
```bash
make
```


## Launch

Execute the webserv binary with a configuration file (.conf) entered as parameter. If no parameter is provided, webserv will try to configure itself using the `/conf_files/ConfigBase.conf` file.
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

#### listen

#### server_name

#### host

#### error_page

### location options

#### autoindex

#### upload_dir

#### cgi

#### allow_methods

#### return

### options viable in both scopes

#### root

#### index

#### client_max_body_size
