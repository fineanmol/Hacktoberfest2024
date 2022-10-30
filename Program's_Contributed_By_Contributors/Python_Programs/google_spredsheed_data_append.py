from googleapiclient.discovery import build
from google.oauth2 import service_account


SERVICE_ACCOUNT_FILE = 'credentials_json_file_name.json'
SCOPES = ['https://www.googleapis.com/auth/spreadsheets']

creds = None
creds = service_account.Credentials.from_service_account_file(
        SERVICE_ACCOUNT_FILE, scopes=SCOPES)

SPREADSHEET_ID = 'spredsheetid_paste_here'
RANGE = 'Sheet1!D2:E989'


service = build('sheets', 'v4', credentials=creds)

sheet = service.spreadsheets()
result = sheet.values().get(spreadsheetId=SPREADSHEET_ID,
                                range=RANGE).execute()
values = result.get('values', [])

value_input_option = 'USER_ENTERED'
insert_data_option = 'OVERWRITE'
clear = sheet.values().clear(spreadsheetId=SPREADSHEET_ID, range=RANGE).execute()

arr = ['1' , 'lakshan' , '25', 'blue']

def gsht(arr):
    value_range_body = {
        "values": arr
    } 
    request = sheet.values().append(spreadsheetId=SPREADSHEET_ID, range='Sheet1!D2', valueInputOption=value_input_option,
                                        insertDataOption=insert_data_option, body=value_range_body).execute()
    print(clear)



