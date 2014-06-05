(function ($) {
  Drupal.behaviors.wsnplatform_charts = {
    attach:function () {
      if (Drupal.settings.wsnplatform.charts) {
        for (var chart in Drupal.settings.wsnplatform.charts) {
          new Highcharts.Chart(Drupal.settings.wsnplatform.charts[chart]);
        }
      }
    }
  };
})(jQuery);
