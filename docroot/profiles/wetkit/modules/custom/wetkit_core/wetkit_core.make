; WetKit Core Makefile

api = 2
core = 7.x

; Modules

projects[advanced_help][version] = 1.1
projects[advanced_help][subdir] = contrib

projects[apps][version] = 1.0-beta7
projects[apps][subdir] = contrib
projects[apps][patch][1790902] = http://drupal.org/files/1790902-check-last-modified-existing.patch

projects[better_formats][version] = 1.0-beta1
projects[better_formats][subdir] = contrib
projects[better_formats][patch][1717470] = http://drupal.org/files/issues/better_formats_strict_warning-1717470-03.patch
projects[better_formats][patch][1712360] = http://drupal.org/files/issues/better_formats_description-1712360-02.patch

projects[ctools][version] = 1.4
projects[ctools][subdir] = contrib
projects[ctools][patch][1630820] = http://drupal.org/files/issues/ctools-entity_field_value-1630820-72.patch
projects[ctools][patch][2195211] = http://drupal.org/files/issues/ctools-n2195211-entity-from-field-access-callback-15.patch
projects[ctools][patch][2195471] = http://drupal.org/files/issues/ctools-n2195471-29.patch
projects[ctools][patch][2198447] = http://drupal.org/files/issues/fix-panel-arguments-to-views-2198447-8.patch

projects[date][version] = 2.7
projects[date][subdir] = contrib

projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][patch][1861054] = http://drupal.org/files/fix-defaultconfig_rebuild_all.patch
projects[defaultconfig][patch][2008178] = http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch
projects[defaultconfig][patch][2043307] = http://drupal.org/files/defaultconfig_include_features_file.patch
projects[defaultconfig][patch][2042799] = http://drupal.org/files/default_config_delete_only_if_overriden.patch

projects[devel][version] = 1.4
projects[devel][subdir] = contrib

projects[diff][version] = 3.2
projects[diff][subdir] = contrib

projects[elements][version] = 1.4
projects[elements][subdir] = contrib

projects[entity][version] = 1.5
projects[entity][subdir] = contrib

projects[entityreference][version] = 1.1
projects[entityreference][subdir] = contrib

projects[entityreference_prepopulate][version] = 1.4
projects[entityreference_prepopulate][subdir] = contrib

projects[entity_view_mode][version] = 1.0-rc1
projects[entity_view_mode][subdir] = contrib

projects[fape][version] = 1.2
projects[fape][subdir] = contrib

projects[features][version] = 2.0
projects[features][subdir] = contrib
projects[features][patch][2047253] = http://drupal.org/files/issues/features_lock_functionality-2047253-01.patch

projects[fences][version] = 1.x-dev
projects[fences][subdir] = contrib
projects[fences][type] = module
projects[fences][download][type] = git
projects[fences][download][revision] = 67206b5
projects[fences][download][branch] = 7.x-1.x

projects[field_collection][version] = 1.x-dev
projects[field_collection][subdir] = contrib
projects[field_collection][download][type] = git
projects[field_collection][download][revision] = ae778f2
projects[field_collection][download][branch] = 7.x-1.x
projects[field_collection][patch][1344672] = http://drupal.org/files/issues/field_collection-et-1344672-187.patch
projects[field_collection][patch][2075325] = http://drupal.org/files/issues/field_collection-field_collection_uuid-2075325-3.patch

projects[field_group][version] = 1.3
projects[field_group][subdir] = contrib
projects[field_group][patch][2129805] = http://drupal.org/files/issues/incorrect_markup_2129805_1.patch

projects[hierarchical_select][version] = 3.0-alpha6
projects[hierarchical_select][subdir] = contrib
projects[hierarchical_select][patch][828418] = http://drupal.org/files/issues/hierarchical_select_attachbehavior-828418-37.patch

projects[libraries][version] = 2.2
projects[libraries][subdir] = contrib

projects[link][version] = 1.2
projects[link][subdir] = contrib

projects[linkchecker][version] = 1.x-dev
projects[linkchecker][type] = module
projects[linkchecker][subdir] = contrib
projects[linkchecker][download][type] = git
projects[linkchecker][download][revision] = 6665254
projects[linkchecker][download][branch] = 7.x-1.x

projects[menu_attributes][version] = 1.x-dev
projects[menu_attributes][subdir] = contrib
projects[menu_attributes][download][type] = git
projects[menu_attributes][download][revision] = ed7e9aa
projects[menu_attributes][download][branch] = 7.x-1.x

projects[menu_block][version] = 2.x-dev
projects[menu_block][subdir] = contrib
projects[menu_block][download][type] = git
projects[menu_block][download][revision] = 32ab1cf
projects[menu_block][download][branch] = 7.x-2.x
projects[menu_block][patch][2199997] = http://drupal.org/files/issues/fix_menu_system-2199997-14.patch
projects[menu_block][patch][2199998] = http://drupal.org/files/issues/fix_menu_language-2199997-20.patch

projects[password_policy][version] = 1.5
projects[password_policy][subdir] = contrib

projects[panelizer][version] = 3.x-dev
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][revision] = ca7e1cb
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][patch][2053721] = http://drupal.org/files/issues/panelizer-n2053721-15.patch

projects[panels][version] = 3.4
projects[panels][subdir] = contrib
projects[panels][patch][2192355] = http://drupal.org/files/issues/i18n_panels_uuid_undefined-2192355-01.patch
projects[panels][patch][2199391] = http://drupal.org/files/issues/panels_layout_undefined_js-2199391-04.patch

projects[panopoly_magic][version] = 1.5
projects[panopoly_magic][subdir] = contrib
projects[panopoly_magic][patch][2179413] = http://drupal.org/files/issues/panels_undefined_styles-2179413-04.patch
;projects[panopoly_magic][patch][1983788] = http://drupal.org/files/issues/panopoly_magic-1983788-6.patch
;projects[panopoly_magic][patch][2144021] = http://drupal.org/files/issues/panopoly_magic_entity_view_modes-2144021-7.patch
;projects[panopoly_magic][patch][2160731] = http://drupal.org/files/issues/panopoly_magic-respect-views-configured-view-mode-2160731.patch

projects[pathauto][version] = 1.x-dev
projects[pathauto][subdir] = contrib
projects[pathauto][download][type] = git
projects[pathauto][download][revision] = 655e451
projects[pathauto][download][branch] = 7.x-1.x
projects[pathauto][patch][936222] = http://drupal.org/files/pathauto-persist-936222-130-pathauto-state.patch

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[rules][version] = 2.6
projects[rules][subdir] = contrib
projects[rules][patch][1810656] = http://drupal.org/files/rules-1810656-25.patch

projects[strongarm][version] = 2.0
projects[strongarm][subdir] = contrib

projects[token][version] = 1.5
projects[token][subdir] = contrib

projects[total_control][version] = 2.4
projects[total_control][subdir] = contrib
projects[total_control][patch][2134401] = http://drupal.org/files/issues/filtered_html_dashboard-2134401-01.patch
projects[total_control][patch][2230019] = http://drupal.org/files/issues/array_key_exists_comments-2230019-01.patch

projects[transliteration][version] = 3.2
projects[transliteration][subdir] = contrib

projects[uuid][version] = 1.x-dev
projects[uuid][subdir] = contrib
projects[uuid][download][type] = git
projects[uuid][download][revision] = 45d745c
projects[uuid][download][branch] = 7.x-1.x
projects[uuid][patch][1969222] = http://drupal.org/files/uuid-file-entity-1969222-1.patch
projects[uuid][patch][2074599] = http://drupal.org/files/uuid_remove_contrib_support-2074599-2.patch
projects[uuid][patch][2074621] = http://drupal.org/files/uuid_services_field_collection_revisions.patch
projects[uuid][patch][2145567] = http://drupal.org/files/issues/uuid_ctools_context-2145567-01.patch

projects[uuid_features][version] = 1.0-alpha4
projects[uuid_features][subdir] = contrib
projects[uuid_features][patch][2153157] = http://drupal.org/files/issues/uuid_features-undefined_index_when_processing_orphanned_bundles-2153157-2.patch

projects[uuid_link][version] = 1.0-beta3
projects[uuid_link][subdir] = contrib
projects[uuid_link][patch][2101455] = http://drupal.org/files/uuid_link_entity_translation-2101455-9.patch

projects[views][version] = 3.7
projects[views][subdir] = contrib
projects[views][patch][1810656] = http://drupal.org/files/views-3.x-dev-issue_1331056-36.patch
projects[views][patch][1863358] = http://drupal.org/files/1863358-grid-format-striping-8.patch
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch

projects[views_autocomplete_filters][version] = 1.1
projects[views_autocomplete_filters][subdir] = contrib

projects[views_bulk_operations][version] = 3.2
projects[views_bulk_operations][subdir] = contrib

projects[webform][version] = 4.0-beta2
projects[webform][subdir] = contrib
projects[webform][patch][2076483] = http://drupal.org/files/issues/webform_uuid-2076483-4.patch

projects[workbench][version] = 1.2
projects[workbench][subdir] = contrib
projects[workbench][patch][1354320] = http://drupal.org/files/content-creation-permissions-1354320-6.patch
projects[workbench][patch][1388220] = http://drupal.org/files/workbench-my_edits_view-1388220-14.patch
projects[workbench][patch][2075467] = http://drupal.org/files/issues/workbench_uuid-2075467-01.patch

projects[workbench_moderation][version] = 1.x-dev
projects[workbench_moderation][subdir] = contrib
projects[workbench_moderation][type] = module
projects[workbench_moderation][download][type] = git
projects[workbench_moderation][download][revision] = a90378d
projects[workbench_moderation][download][branch] = 7.x-1.x
; Trivial
projects[workbench_moderation][patch][1237558] = http://drupal.org/files/double-messages-1237558-7.patch
projects[workbench_moderation][patch][1732802] = http://drupal.org/files/workbench-moderation-draft-terminology-1732802-1.patch
projects[workbench_moderation][patch][1785798] = http://drupal.org/files/workbench_moderation-revision-moderation-edit-link-1785798-14.patch
projects[workbench_moderation][patch][1836680] = http://drupal.org/files/workbench-moderation-solr-index-1836680-1.patch
projects[workbench_moderation][patch][1445824] = http://drupal.org/files/workbench_moderation-better_migration_support-1445824-11.patch
projects[workbench_moderation][patch][1919706] = http://drupal.org/files/issues/workbench_moderation-entitymalformed-1919706-3.patch
; Extensively Tested
projects[workbench_moderation][patch][1260112] = http://drupal.org/files/workbench_moderation_is_current-1260112-58.patch
projects[workbench_moderation][patch][1330562] = http://drupal.org/files/workbench_moderation-entity-cache-1330562-22.patch
projects[workbench_moderation][patch][1571614] = http://drupal.org/files/workbench-moderation-1571614-1.patch
projects[workbench_moderation][patch][1946392] = http://drupal.org/files/et_language-1946392-1.patch
; Stable
projects[workbench_moderation][patch][1402860] = http://drupal.org/files/issues/workbench_moderation-panelizer_revisions-1402860-39.patch
projects[workbench_moderation][patch][1408858] = http://drupal.org/files/default-moderation-state-1408858-12.patch
projects[workbench_moderation][patch][1436260] = http://drupal.org/files/issues/1436260-workbench_moderation-states-vbo-38.patch
projects[workbench_moderation][patch][2098151] = http://drupal.org/files/playnicewithpanels-2098151-01.patch
projects[workbench_moderation][patch][2070389] = http://drupal.org/files/workbench_moderation-correctly_update_status-2070389-2.patch
; Queued
;projects[workbench_moderation][patch][1408838] = http://drupal.org/files/workbench_moderation-revision-operations-performance-1408838-38.patch

; Libraries

libraries[querypath][download][type] = git
libraries[querypath][download][branch] = 3.x
libraries[querypath][download][revision] = eeb67cc
libraries[querypath][download][url] = https://github.com/technosophos/querypath.git
