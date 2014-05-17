; WetKit Admin Makefile

api = 2
core = 7.x

; Contrib

projects[admin_menu][version] = 3.0-rc4
projects[admin_menu][subdir] = contrib

projects[admin_views][version] = 1.2
projects[admin_views][subdir] = contrib

projects[backports][version] = 1.0-alpha1
projects[backports][subdir] = contrib

projects[date_popup_authored][version] = 1.1
projects[date_popup_authored][subdir] = contrib
projects[date_popup_authored][patch][2256611] = http://drupal.org/files/issues/hook_form_node_form_alter-2256611-01.patch

projects[jquery_update][version] = 2.4
projects[jquery_update][subdir] = contrib
projects[jquery_update][patch][1969244] = http://drupal.org/files/issues/jquery_update-theme-specific-version-1969244-22.patch
projects[jquery_update][patch][2056413] = http://drupal.org/files/issues/jquery_update-2056413-08.patch
projects[jquery_update][patch][2123973] = http://drupal.org/files/issues/jquery_effects_missing-2123973-14.patch

projects[module_filter][version] = 1.8
projects[module_filter][subdir] = contrib
