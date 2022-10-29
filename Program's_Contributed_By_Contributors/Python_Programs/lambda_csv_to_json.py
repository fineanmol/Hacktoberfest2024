import boto3
import urllib3
import csv
import json
     
def lambda_handler(event, context):
         
    object_get_context = event["getObjectContext"]
    request_route = object_get_context["outputRoute"]
    request_token = object_get_context["outputToken"]
    s3_url = object_get_context["inputS3Url"]
     
    # Get object from S3
    http = urllib3.PoolManager()
    response = http.request('GET', s3_url)
    original_object = response.data.decode('utf-8').splitlines()
    csv_reader = csv.DictReader(original_object)
    data = {}
     
    for rows in csv_reader:
        id = rows['Identifier']
        data[id] = rows
             
    json_object = json.dumps(data, indent=4)
     
    # Write object back to S3 Object Lambda
    s3 = boto3.client('s3')
    s3.write_get_object_response(
        Body=json_object,
        RequestRoute=request_route,
        RequestToken=request_token)
     
    return {'status_code': 200}