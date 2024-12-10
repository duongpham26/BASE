package com.duongpham26.demo.service;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;

import com.duongpham26.demo.entity.RestResponse;


@ControllerAdvice
@ResponseBody
public class GlobalException {
   @ExceptionHandler(value = IdInvalidException.class) 
   public ResponseEntity<RestResponse<Object>> handleInException(IdInvalidException idException) {
      RestResponse<Object> res = new RestResponse<Object>();
      res.setStatusCode(HttpStatus.BAD_REQUEST.value());
      res.setError(idException.getMessage());
      res.setMessage("IdInvalidException");

      return ResponseEntity.badRequest().body(res);
   }
}
