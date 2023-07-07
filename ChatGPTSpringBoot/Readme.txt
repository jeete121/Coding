JDK ≥ 1.8 + Maven > 3.X + Spring Boot 3.X + Lombok + OpenAI API Key

In order to use OpenAI API with Spring Boot, you will need a personalized API key.

Create an account on OpenAI Website and generate the token from:

https://platform.openai.com/account/api-keys




Input for the application


{
    "model": "text-davinci-003",
    "prompt": "Kakfa producer code in java",
    "temperature": 0.3,
    "max_tokens": 100,
    "top_p": 1,
    "frequency_penalty": 0,
    "presence_penalty": 0
}


{
    "id": "cmpl-7ZiuAxJKL74ZzXxd3krTaXeDYhYk9",
    "object": "text_completion",
    "created": "+4625606-03-20",
    "model": "text-davinci-003",
    "choices": [
        {
            "text": "\n\nimport java.util.Properties;\nimport org.apache.kafka.clients.producer.KafkaProducer;\nimport org.apache.kafka.clients.producer.Producer;\nimport org.apache.kafka.clients.producer.ProducerRecord;\n\npublic class SimpleProducer {\n\n   public static void main(String[] args) throws Exception{\n      String topicName = \"",
            "index": 0,
            "finish_reason": "length"
        }
    ],
    "usage": {
        "prompt_tokens": 7,
        "completion_tokens": 100,
        "total_tokens": 107
    }
}

To get Proper output update max_tokens to 4000


Swgger URL::
http://localhost:8080/swagger-ui/index.html

