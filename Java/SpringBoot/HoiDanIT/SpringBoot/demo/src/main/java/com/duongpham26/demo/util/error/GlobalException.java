package com.duongpham26.demo.util.error;

import java.net.BindException;
import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;

import com.duongpham26.demo.entity.RestResponse;

@ControllerAdvice
@ResponseBody
public class GlobalException {
   @ExceptionHandler(value = {
      IdInvalidException.class,
      UsernameNotFoundException.class,
      BadCredentialsException.class
   }) 
   public ResponseEntity<RestResponse<Object>> handleInException(IdInvalidException idException) {
      RestResponse<Object> res = new RestResponse<Object>();
      res.setStatusCode(HttpStatus.BAD_REQUEST.value());
      res.setError(idException.getMessage());
      res.setMessage("Exception occurs");
      return ResponseEntity.badRequest().body(res);
   }

   @ExceptionHandler(value = MethodArgumentNotValidException.class)
   public ResponseEntity<RestResponse<Object>> validationError(MethodArgumentNotValidException ex) {
      BindingResult result = ex.getBindingResult();
      final List<FieldError> fieldError = result.getFieldErrors(); 
      List<String> errors = fieldError.stream().map(f -> f.getDefaultMessage()).collect(null);
      
      RestResponse<Object> res = new RestResponse<>();
      res.setStatusCode(HttpStatus.BAD_REQUEST.value());
      res.setError(ex.getBody().getDetail());

      return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(res);
   }

   // @ExceptionHandler(MethodArgumentValidException.class)
   // public ResponseEntity<RestResponse<Object>> validError(MethodArgumentValidException.class)
}
