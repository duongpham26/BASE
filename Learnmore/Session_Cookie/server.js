const express = require('express');
const cookieParser = require('cookie-parser');
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());
app.set('view engine', 'ejs');

// fake DB (MySQL, MoongDB)
const db = {
   users: [
      {
         id: 1,
         email: 'duongpham@gmail.com',
         password: '123456',
         name: 'Pham Duong',
      }
   ]
}

const sessions = {};

app.get('/', (req, res) => {
   res.render('pages/index');
});

app.get('/login', (req, res) => {
   res.render('pages/login');
});

app.post('/login', (req, res) => {
   const { email, password } = req.body;
   const user = db.users.find((user) => user.email === email && user.password === password);
   if(user) {
      const sessionId = Date.now().toString();
      sessions[sessionId] = {
         userId: user.id, 
      };
      console.log(sessions);
      res.setHeader(
         'Set-Cookie',
         `sessionId=${sessionId}; max-age=3600; httpOnly` 
      ).redirect('/dashboard');
      return;
   };  
   res.send('Ok');
});

app.get('/dashboard', (req, res) => {
   const session = sessions[req.cookies.sessionId];
   console.log(session);
   if(!session) {
      return res.redirect('/login');
   }
   const user = db.users.find((user) => user.id === session.userId);
   if(!user) return res.redirect('/login');
   res.render('pages/dashboard', {user});
});

app.listen(port, () => {
   console.log(`App is running on port ${port}`);
});