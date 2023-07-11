DK ≥ 1.8 + Maven > 3.X + Spring Boot 3.X + Lombok + OpenAI API Key

In order to use OpenAI API with Spring Boot, you will need a personalized API key.

Create an account on OpenAI Website and generate the token from:

https://platform.openai.com/account/api-keys





http://localhost:8080/chat/feign


Input

{
    "model": "gpt-3.5-turbo",
    "messages": [
        {
            "role": "user",
            "content": "what is java"
        }
    ],
    "n": 1,
    "temperature": 0.3
}


Output


{
    "id": "chatcmpl-7bBkUNxlfZXs5FTHC6HsOBbtzYbeL",
    "object": "chat.completion",
    "created": "1970-01-20T13:11:37.654+00:00",
    "model": "gpt-3.5-turbo-0613",
    "choices": [
        {
            "index": 0,
            "message": {
                "role": "assistant",
                "content": "Java is a high-level, object-oriented programming language that was developed by Sun Microsystems (now owned by Oracle) in the mid-1990s. It is known for its platform independence, meaning that Java programs can run on any device or operating system that has a Java Virtual Machine (JVM) installed. Java is widely used for developing a variety of applications, including desktop software, mobile apps, web applications, and enterprise systems. It has a large and active community of developers and is known for its robustness, security, and scalability."
            },
            "finish_reason": "stop"
        }
    ],
    "usage": {
        "prompt_tokens": 10,
        "completion_tokens": 109,
        "total_tokens": 119
    }
}