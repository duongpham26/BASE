<%@ page contentType="text/html" pageEncoding="UTF-8" %>
   <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
      <%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>

         <!DOCTYPE html>
         <html lang="en">

         <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Document</title>

            <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"
               integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
               crossorigin="anonymous">

            <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
               integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
               crossorigin="anonymous"></script>

            <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>

            <!-- <link rel="stylesheet" href="/css/demo.css"> -->

         </head>

         <body>

            <div class="container mt-5">

               <div class="row">
                  <div class="col-md-6 mb-3 mx-auto">
                     <h2>Create a user</h2>
                     <hr />
                     <form:form action="/admin/user/create" method="post" modelAttribute="newUser">

                        <div class="mb-3">
                           <form:label class="form-label" path="email">Email</form:label>
                           <form:input class="form-control" path="email" type="email" />
                        </div>

                        <div class="mb-3">
                           <form:label class="form-label" path="password">Password</form:label>
                           <form:input class="form-control" path="password" type="password" />
                        </div>

                        <div class="mb-3">
                           <form:label class="form-label" path="fullName">Full Name</form:label>
                           <form:input class="form-control" path="fullName" />
                        </div>

                        <div class="mb-3">
                           <form:label class="form-label" path="phone">Phone</form:label>
                           <form:input class="form-control" path="phone" />
                        </div>

                        <div class="mb-3">
                           <form:label class="form-label" path="address">Address</form:label>
                           <form:input class="form-control" path="address" />
                        </div>

                        <button type="submit" class="btn btn-primary mt-3">Submit</button>

                     </form:form>
                  </div>
               </div>

            </div>


         </body>

         </html>