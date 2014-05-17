; WetKit Language Makefile

api = 2
core = 7.x

; Contrib

projects[entity_translation][version] = 1.0-beta3
projects[entity_translation][subdir] = contrib
projects[entity_translation][patch][1866076] = http://drupal.org/files/entity_translation-add_support_no_load_tokens-1866076-7.patch
projects[entity_translation][patch][1516202] = http://drupal.org/files/translation-access-plugin-1516202-2.patch
projects[entity_translation][patch][1925848] = http://drupal.org/files/entitytranslation-incorrect_pathauto_pattern-1925848-8.patch

projects[features_translations][version] = 1.0-beta4
projects[features_translations][subdir] = contrib

projects[i18n][version] = 1.11
projects[i18n][subdir] = contrib

projects[i18nviews][version] = 3.x-dev
projects[i18nviews][type] = module
projects[i18nviews][subdir] = contrib
projects[i18nviews][download][type] = git
projects[i18nviews][download][revision] = 26bd52c
projects[i18nviews][download][branch] = 7.x-3.x
projects[i18nviews][patch][1788832] = http://drupal.org/files/fixed-1788832-1.patch

projects[l10n_client][version] = 1.3
projects[l10n_client][subdir] = contrib

projects[l10n_update][version] = 1.0-beta3
projects[l10n_update][subdir] = contrib

projects[potx][version] = 1.0
projects[potx][subdir] = contrib

projects[stringoverrides][version] = 1.8
projects[stringoverrides][subdir] = contrib

projects[title][version] = 1.x-dev
projects[title][type] = module
projects[title][subdir] = contrib
projects[title][download][type] = git
projects[title][download][revision] = 32e8016
projects[title][download][branch] = 7.x-1.x

projects[variable][version] = 2.5
projects[variable][subdir] = contrib

projects[webform_localization][version] = 4.x-dev
projects[webform_localization][type] = module
projects[webform_localization][subdir] = contrib
projects[webform_localization][download][type] = git
projects[webform_localization][download][revision] = 5039efc
projects[webform_localization][download][branch] = 7.x-4.x
