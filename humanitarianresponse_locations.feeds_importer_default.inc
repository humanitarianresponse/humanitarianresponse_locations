<?php
/**
 * @file
 * humanitarianresponse_locations.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function humanitarianresponse_locations_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_locations';
  $feeds_importer->config = array(
    'name' => 'CSV Locations',
    'description' => 'Import locations from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'bundle' => 'locations',
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'Parent',
            'target' => 'parent_pcode',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'PCode',
            'target' => 'field_location_pcode',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'Local PCode',
            'target' => 'field_local_pcode',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Population',
            'target' => 'field_location_pop',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'WKT',
            'target' => 'field_location:wkt',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_locations'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_locations_geonode';
  $feeds_importer->config = array(
    'name' => 'CSV Locations Geonode',
    'description' => 'Import locations from Geonode',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'bundle' => 'locations',
        'mappings' => array(
          0 => array(
            'source' => 'the_geom',
            'target' => 'field_location:wkt',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Name',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'PCode',
            'target' => 'field_location_pcode',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'Parent',
            'target' => 'parent_pcode',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Population',
            'target' => 'field_location_pop',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_locations_geonode'] = $feeds_importer;

  return $export;
}
