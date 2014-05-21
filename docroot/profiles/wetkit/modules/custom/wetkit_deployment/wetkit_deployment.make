; WetKit Deployment Makefile

api = 2
core = 7.x

; Modules for WetKit Deployment

projects[configuration][version] = 2.0-alpha3
projects[configuration][subdir] = contrib

projects[deploy][version] = 2.x-dev
projects[deploy][subdir] = contrib
projects[deploy][type] = module
projects[deploy][download][type] = git
projects[deploy][download][revision] = 3566fb6
projects[deploy][download][branch] = 7.x-2.x
projects[deploy][patch][1604938] = http://drupal.org/files/deploy-1604938_1.patch
projects[deploy][patch][2052767] = http://drupal.org/files/deploy-undefined_variable_user-2052767-3.patch
projects[deploy][patch][2092335] = http://drupal.org/files/deploy_new_alter_hook-2092335-4.patch

projects[deploy_services_client][version] = 1.0-beta2
projects[deploy_services_client][subdir] = contrib
projects[deploy_services_client][type] = module

projects[entity_dependency][version] = 1.x-dev
projects[entity_dependency][subdir] = contrib
projects[entity_dependency][type] = module
projects[entity_dependency][download][type] = git
projects[entity_dependency][download][revision] = 043c090
projects[entity_dependency][download][branch] = 7.x-1.x
projects[entity_dependency][patch][1538848] = http://drupal.org/files/1538848-missing-bundle-property-5.patch
projects[entity_dependency][patch][1589794] = http://drupal.org/files/entity_dependency_iterator_documentation-1589794-1.patch
projects[entity_dependency][patch][1590280] = http://drupal.org/files/entity_dependency_comment_typos-1590280-1.patch
projects[entity_dependency][patch][1772372] = http://drupal.org/files/documentation-1772372.patch
projects[entity_dependency][patch][2051797] = http://drupal.org/files/2051797-file-bug-1.patch

projects[entity_menu_links][version] = 1.x-dev
projects[entity_menu_links][subdir] = contrib
projects[entity_menu_links][type] = module
projects[entity_menu_links][download][type] = git
projects[entity_menu_links][download][revision] = 5fed421
projects[entity_menu_links][download][branch] = 7.x-1.x
projects[entity_menu_links][patch][2090403] = http://drupal.org/files/entity_menu_links_system_path-2090403-1.patch

projects[environment_indicator][version] = 2.2
projects[environment_indicator][subdir] = contrib

projects[quicktabs][version] = 3.6
projects[quicktabs][subdir] = contrib

projects[services][version] = 3.7
projects[services][subdir] = contrib
projects[services][patch][2200269] = http://drupal.org/files/issues/services-2200269.patch

projects[shared_content][version] = 1.0-beta2
projects[shared_content][subdir] = contrib

projects[uuid_redirect][version] = 1.x-dev
projects[uuid_redirect][subdir] = contrib
projects[uuid_redirect][type] = module
projects[uuid_redirect][download][type] = git
projects[uuid_redirect][download][revision] = ce1ab849
projects[uuid_redirect][download][branch] = 7.x-1.x

projects[xautoload][version] = 3.2
projects[xautoload][subdir] = contrib
