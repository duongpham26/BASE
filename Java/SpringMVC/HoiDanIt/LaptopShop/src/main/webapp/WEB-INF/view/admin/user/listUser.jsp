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
            <div class="container mt-5 px-0">
               <div class="d-flex justify-content-between">
                  <h3>Table User</h3>
                  <a class="btn btn-primary" href="/admin/user/create" role="button">Create User</a>
               </div>
               <hr />

               <table class="table table-bordered table-hover">
                  <thead>
                     <tr>
                        <th scope="col">ID</th>
                        <th scope="col">Email</th>
                        <th scope="col">Full</th>
                        <th scope="col">Action</th>
                     </tr>
                  </thead>

                  <tbody>
                     <tr>
                        <th scope="row">1</th>
                        <td>Mark</td>
                        <td>Otto</td>
                        <td>
                           <button class="btn btn-success" type="submit">View</button>
                           <button class="btn btn-warning" type="submit">Update</button>
                           <button class="btn btn-danger" type="submit">Delete</button>
                        </td>
                     </tr>
                     <tr>
                        <th scope="row">2</th>
                        <td>Jacob</td>
                        <td>Thornton</td>
                        <td>
                           <button class="btn btn-success" type="submit">View</button>
                           <button class="btn btn-warning" type="submit">Update</button>
                           <button class="btn btn-danger" type="submit">Delete</button>
                        </td>
                     </tr>
                  </tbody>
               </table>
            </div>

         </body>

         </html>