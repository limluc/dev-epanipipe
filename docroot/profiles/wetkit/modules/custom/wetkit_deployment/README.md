WxT Deployment
==============
Functionality to facilitate a content staging workflow for [Drupal WxT][drupalwxt].

Key features
------------

* [CTools][ctools] Deployment related plugins
* Default [Environment Indicator][environment_indicator] settings
* Sample Deployment Plans and Deployment EndPoints for interaction with [Deploy][deploy]
* Support for both Batch and individual deployments across all entities
* [Workbench Moderation][workbench_moderation] support for Deployment

Important
---------

* This module isn't enabled by default
* Client: Please run the following drush make in profiles/wetkit directory:
  ```sh
  drush make --no-core modules/custom/wetkit_deployment/wetkit_deployment.make
  ```
* Server: Please run the following drush make in profiles/wetkit directory:
  ```sh
  drush make --no-core modules/custom/wetkit_deployment/wetkit_deployment_service/wetkit_deployment_service.make
  ```
* Enable!


<!-- Links Referenced -->

[ctools]:                       http://drupal.org/project/ctools
[deploy]:                       http://drupal.org/project/wetkit
[drupalwxt]:                    http://drupal.org/project/wetkit
[environment_indicator]:        http://drupal.org/project/environment_indicator
[workbench_moderation]:          http://drupal.org/project/workbench_moderation
