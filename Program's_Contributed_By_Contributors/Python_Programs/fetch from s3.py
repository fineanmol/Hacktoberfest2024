#read file from S3 into dataframe
def fetch_file_from_s3(filepath_name,sheet_no,bucket_name,file_type): 
    s3_conn=create_s3_object()
    s3 = boto3.client('s3')
    try:
        obj = s3_conn.Bucket(bucket_name).Object(filepath_name).get()
        if file_type=='excel':
            df = pd.read_excel(io.BytesIO(obj['Body'].read()),sheet_no)
        elif file_type=='json':
            obj = s3.get_object(Bucket=bucket_name, Key=filepath_name)
            df = pd.read_json(obj['Body'],lines=True, compression='gzip')
        else:
            df = pd.read_csv(io.BytesIO(obj['Body'].read()),sheet_no)
        return df
    except  Exception as e:
        logging_it('issue while fetching data from S3: \n{}'.format(e))
        return False
