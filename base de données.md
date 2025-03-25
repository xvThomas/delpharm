# Base de données

##  Transaction

Séquence d'opérations devant être executées de manière **A**tomique, c'est-à-dire que toutes les opérations doivent être executées (commit) ou aucune (rollback).
De plus, une transaction doit être **C**ohérente, c'est-à-dire que les opérations doivent respecter les contraintes d'intégrité de la base de données.
les transactions doivent être **I**solées les unes des autres, c'est-à-dire que les opérations d'une transaction ne doivent pas interférer avec celles d'une autre transaction.
Une fois une transaction commitée, les opérations sont persistées dans la base de données (**D**urablilité).

## Foreign Key

Une clé étrangère est une colonne ou un ensemble de colonnes dans une table qui fait référence à la clé primaire d'une autre table. La clé étrangère peut être utilisée pour identifier chaque ligne d'une table de manière unique.

## Jointure

Une jointure est une opération qui combine des enregistrements de deux ou plusieurs tables en fonction d'une relation entre les colonnes de ces tables.

## PHASE - OPERATION - TYPE-OPER

| Affirmation                                                            | Vrai | Faux |
|------------------------------------------------------------------------|------|------|
| Une opération n'appartient qu'à une seule phase                        | X    |      |
| Un type d'opération peut décrire plusieurs opérations                  | X    |      |
| On peut supprimer une opération appartenant à une phase (pas clair...) | X    |      |
| La suppression d'une phase entraîne la suppression d'une opération     |      | X    |

```sql
SELECT OPERATION.NOM_OPERATION 
FROM OPERATION, PHASE, TYPE_OPERATION
WHERE OPERATION.ID_PHASE = PHASE.ID_PHASE
    AND OPERATION.ID_TYPE_OPERATION = TYPE_OPER.ID_TYPE_OPER
    AND PHASE.ID_PHASE = 'PHASE1' 
    AND TYPE_OPER.NOM_TYPE_OPER = 'FABR';
```

(peut également être réalisée avec des LEFT JOIN)