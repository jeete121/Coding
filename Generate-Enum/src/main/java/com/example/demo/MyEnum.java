package com.example.demo;

public enum MyEnum {

	NOT_SO_SIMPLE("NOTSOSIMPLE"),
	PROPERTY_WITH_CAMEL_CASE("CAMELCASE"),
	SIMPLE("SIMPLE");

    private MyEnum(String value){
        this.value = value;
    }

    private String value;

    public String getValue(){
        return this.value;
    }

}