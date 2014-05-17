; WetKit Search API Makefile

api = 2
core = 7.x

; Search API

projects[search_api][version] = 1.11
projects[search_api][subdir] = contrib

projects[search_api_solr][version] = 1.4
projects[search_api_solr][subdir] = contrib

projects[search_api_db][version] = 1.2
projects[search_api_db][subdir] = contrib

; Solr PHP Client Library

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.zip
