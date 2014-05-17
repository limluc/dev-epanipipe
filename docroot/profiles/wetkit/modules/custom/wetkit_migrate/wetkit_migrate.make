; WetKit Migrate Makefile

api = 2
core = 7.x

; Modules needed for Migration

projects[migrate][version] = 2.x-dev
projects[migrate][type] = module
projects[migrate][subdir] = contrib
projects[migrate][download][type] = git
projects[migrate][download][revision] = 9511d72
projects[migrate][download][branch] = 7.x-2.x

projects[migrate_extras][version] = 2.5
projects[migrate_extras][type] = module
projects[migrate_extras][subdir] = contrib
projects[migrate_extras][patch][2126725] = http://drupal.org/files/issues/migrate_media_attributes-2126725-01.patch
