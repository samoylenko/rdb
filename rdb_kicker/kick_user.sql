COMMIT;
SET TERM ^ ;

CREATE PROCEDURE "KICK_USER"
(
ID_USER INTEGER
)
AS

begin
 post_event 'EXIT_'||ID_USER;
 post_event 'USER_REFRESH';
 suspend;
end ^

SET TERM ; ^
COMMIT;

execute procedure KICK_USER( 1 );

COMMIT;

drop procedure KICK_USER;



