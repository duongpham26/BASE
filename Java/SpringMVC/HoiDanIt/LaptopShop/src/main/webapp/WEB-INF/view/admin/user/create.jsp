<%@ page contentType="text/html" pageEncoding="UTF-8" %>
   <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

      <!DOCTYPE html>
      <html lang="en">

      <head>
         <meta charset="UTF-8">
         <meta name="viewport" content="width=device-width, initial-scale=1.0">
         <title>Document</title>

         <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">

         <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"></script>

         <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>

         <!-- <link rel="stylesheet" href="/css/demo.css"> -->

      </head>

      <body>

         <div class="container-sm">

            <div class="row">
               <div class="col">
                  <form:form action="/create-user" method="post" modelAttribute="user">
                     <h2 class="border-bottom border-1 py-3">Create a user</h2>
                     <div class="">
                        <label for="inputEmail4" class="form-label">Email</label>
                        <input type="email" class="form-control" id="inputEmail4">
                     </div>

                     <div class="">
                        <label for="inputPassword4" class="form-label">Password</label>
                        <input type="password" class="form-control" id="inputPassword4">
                     </div>

                     <div class="">
                        <label for="inputFullName4" class="form-label">Full Name</label>
                        <input type="text" class="form-control" id="inputFullName4">
                     </div>

                     <div class="">
                        <label for="inputPhone4" class="form-label">Phone</label>
                        <input type="text" class="form-control" id="inputPhone4">
                     </div>

                     <div class="">
                        <label for="inputAdress4" class="form-label">Address</label>
                        <input type="text" class="form-control" id="inputAdress4">
                     </div>

                     <button type="submit" class="btn btn-primary mt-3">Submit</button>

                  </form:form>
               </div>
            </div>

         </div>


      </body>

      </html>