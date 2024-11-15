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

         <div class="container mt-5">

            <div class="row">
               <div class="col-md-6 mb-3 mx-auto">
                  <h2>Create a user</h2>
                  <hr />
                  <form action="admin/user/create" method="post" modelAttribute="user">
                     <div class="mb-3">
                        <label class="form-label">Email</label>
                        <input type="email" class="form-control">
                     </div>

                     <div class="mb-3">
                        <label class="form-label">Password</label>
                        <input type="password" class="form-control">
                     </div>

                     <div class="mb-3">
                        <label class="form-label">Full Name</label>
                        <input type="text" class="form-control">
                     </div>

                     <div class="mb-3">
                        <label class="form-label">Phone</label>
                        <input type="text" class="form-control">
                     </div>

                     <div class="mb-3">
                        <label class="form-label">Address</label>
                        <input type="text" class="form-control">
                     </div>

                     <button type="submit" class="btn btn-primary mt-3">Submit</button>

                  </form>
               </div>
            </div>

         </div>


      </body>

      </html>