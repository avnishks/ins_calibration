function [sys,x0,str,ts]=quatupdt(t,x,u,flag,dt,a,b,c,d)
%quaternion update. correspondences a,b,c,d here -> q1,q2,q3,q0 book

switch flag

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0         
    [sys,x0,str,ts] = mdlInitializeSizes(dt,a,b,c,d);

  %%%%%%%%%%%%%%%%%%%%%%%%
  % Others  &  Terminate %
  %%%%%%%%%%%%%%%%%%%%%%%%
  case {1,9}
    sys = []; % do nothing

  %%%%%%%%%%%%%%%
  % Update      %
  %%%%%%%%%%%%%%%
  case 2
    sys = mdlUpdate(t,x,u,dt);

  %%%%%%%%%%
  % Output %
  %%%%%%%%%%  
  case 3
    sys = mdlOutputs(t,x,u); 
  %%%%%%%%%%%%%%%
  % Update      %
  %%%%%%%%%%%%%%%
  
  case 4
    sys = mdlGetTimeofNextVarHit(t,x,u,dt);

    
  otherwise
    error(['unhandled flag = ',num2str(flag)]);
    
end

% end quatupdt
%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys,x0,str,ts] = mdlInitializeSizes(dt,a,b,c,d)

   sizes = simsizes;
   sizes.NumContStates  = 0;
   sizes.NumDiscStates  = 4;
   sizes.NumOutputs     = 4;
   sizes.NumInputs      = 3;
   sizes.DirFeedthrough = 0;
   sizes.NumSampleTimes = 1;

   sys = simsizes(sizes);
   str = [];
   x0(1) = a;
   x0(2) = b;
   x0(3) = c;
   x0(4) = d;
   ts  = [dt 0];   % sample time: [period, offset]


% end mdlInitializeSizes
%
%=============================================================================
% mdlUpdate
% Compute updates for discrete states.
%=============================================================================
%
function sys = mdlUpdate(t,x,u,dt)
%
% a, b, c, d = x(1), x(2), x(3), x(4)
% dtx, dty, dtz = u(1), u(2), u(3)
%
      c1 = -(u(1)^2+u(2)^2+u(3)^2)/4.0;
      c2 = c1^2;
      f1 = 1.0 + c1/2.0 + c2/24.0;
      f2 = 0.5*( 1.0 + c1/6.0 + c2/120.0 );
      
      ux1 = f1*x(1) + f2*(             u(3)*x(2) - u(2)*x(3) + u(1)*x(4) );
      ux2 = f1*x(2) + f2*(-u(3)*x(1)             + u(1)*x(3) + u(2)*x(4) );
      ux3 = f1*x(3) + f2*( u(2)*x(1) - u(1)*x(2)             + u(3)*x(4) );
      ux4 = f1*x(4) + f2*(-u(1)*x(1) - u(2)*x(2) - u(3)*x(3)             );
      
      c3 = ux1^2+ux2^2+ux3^2+ux4^2;
      
      x(1) = ux1/sqrt(c3);
      x(2) = ux2/sqrt(c3);
      x(3) = ux3/sqrt(c3);
      x(4) = ux4/sqrt(c3);

  sys = x;

% end mdlUpdate

%
%=============================================================================
% mdlOutputs
% Return the output vector for the S-function
%=============================================================================
%
function sys = mdlOutputs(t,x,u)

   sys = x;

% end mdlOutputs

%=============================================================================
% mdlGetTimeofNextVarHit
%=============================================================================
function sys = mdlGetTimeofNextVarHit(t,x,u,dt)

   sys = t + dt;

% end mdlGetTimeofNextVarHit