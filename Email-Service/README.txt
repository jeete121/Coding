The Gmail Id used to login into your Gmail account can be provided as the username.


For password generation, 2-step verification needs to be enabled for your account as follows:



Following that, AppPassword needs to be created using the following path:

Login to Gmail 
    -> Manage your Google Account 
        -> Security 
            -> App Passwords 
                -> Provide your login password 
                    -> Select app with a custom name 
                        -> Click on Generate






EMAIL WITHOUT ATTACHMENT

URL:: http://localhost:8080/sendMail


INPUT

{
    "recipient": "your-email-id",
    "msgBody": "Successfully Sent Message",
    "subject": "Simple Mail"
}

OUTPUT

{
    "status": 200,
    "description": "Mail Sent Successfully..."
}



EMAIL WITH ATTACHMENT

URL:: http://localhost:8080/sendMailWithAttachment


INPUT
{
    "recipient": "your-email-id",
    "msgBody": "Successfully Sent Message",
    "subject": "Kafka Commands",
    "attachment": "path-of-the-attachment"
}

OUTPUT
{
    "status": 200,
    "description": "Mail Sent Successfully with attachment"
}

